#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int SIZE = 1048576;

struct SegTree{
    int size, start;
    int arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int here, int val){
        here += start;
        arr[here] += val;
        while (here){
            here /= 2;
            arr[here] = arr[here * 2] + arr[here * 2 + 1];
        }
    }

    int sum(int l, int r){
        l += start;
        r += start;
        int ret = 0;
        while (l <= r){
            if (l % 2 == 1) ret += arr[l++];
            if (r % 2 == 0) ret += arr[r--];
            l /= 2; r /= 2;
        }
        return ret;
    }
};

int main() {
    fastio;
    int N;
    cin >> N;
    vector<int> v(N), pos(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        pos[i] = v[i];
    }
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
    unordered_map<int, int> inv_pos;
    for (int i = 0; i < sz(pos); i++) {
        inv_pos[pos[i]] = i;
    }
    SegTree segTree(N);
    for (auto k : v) {
        int inv_k = inv_pos[k];
        cout << segTree.sum(inv_k + 1, N - 1) + 1 << '\n';
        segTree.update(inv_k, 1);
    }
}