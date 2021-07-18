#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int SIZE = 2097152;

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
        while (here){
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
    fastio;
    int N, M;
    cin >> N >> M;
    SegTree segTree(2001);
    vector<pi> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].x >> edges[i].y;
    }
    sort(all(edges));
    int before = -1; long long answer = 0;
    vector<int> st;
    for (auto[u, v] : edges) {
        if (u != before) {
            for (auto w : st) {
                segTree.update(w, 1);
            }
            st.clear();
        }
        answer += segTree.sum(v + 1, N);
        before = u;
        st.push_back(v);
    }
    cout << answer << '\n';
}