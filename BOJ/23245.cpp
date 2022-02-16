#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int INF = 1e9;
const int SIZE = 2097152;
const int MAX = 1000001;

struct SegTree{
    int size, start;
    long long arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int here, long long val){
        here += start;
        arr[here] += val;
        while (here) {
            here /= 2;
            arr[here] = arr[here * 2] + arr[here * 2 + 1];
        }
    }

    long long sum(int l, int r){
        l += start;
        r += start;
        long long ret = 0;
        while (l <= r){
            if (l % 2 == 1) ret += arr[l++];
            if (r % 2 == 0) ret += arr[r--];
            l /= 2; r /= 2;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];
    vector<pi> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = {p[i], q[i]};
    }
    sort(all(r)); // p 기준으로 정렬
    map<int, vector<int>> interval;
    for (int i = 0; i < n; i++) {
        interval[r[i].x].push_back(r[i].y);
    }
    SegTree leftTree(MAX + 1), rightTree(MAX + 1);
    for (int i = 0; i < n; i++) {
        rightTree.arr[rightTree.start + r[i].y] += 1;
    }
    rightTree.prepare();
    long long answer = 0;
    for (auto [k, v] : interval) {
        for (auto i : v) {
            rightTree.update(i, -1);
        }
        for (auto i : v) {
            answer += leftTree.sum(0, i - 1) * rightTree.sum(i + 1, MAX);
        }
        for (auto i : v) {
            leftTree.update(i, 1);
        }
    }
    cout << answer << '\n';
}