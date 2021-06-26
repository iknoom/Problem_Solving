#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
const int MAX = 200000;
int N, M, l_idx[MAX], r_idx[MAX], cnt;
vector<int> adj[MAX];

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

    long long sum(int here){
        long long ret = 0;
        here += start;
        ret += arr[here];
        while (here){
            here /= 2;
             ret += arr[here];
        }
        return ret;
    }

    void update(int l, int r, long long val){
        l += start;
        r += start;
        while (l <= r){
            if (l % 2 == 1) arr[l++] += val;
            if (r % 2 == 0) arr[r--] += val;
            l /= 2; r /= 2;
        }
    }
};

void dfs(int u) {
    l_idx[u] = cnt++;
    for (int v : adj[u]) {
        dfs(v);
    }
    r_idx[u] = cnt;
}

int main() {
    fastio;
    cin >> N >> M;
    for (int u = 0; u < N; u++) {
        int p;
        cin >> p;
        if (p < 0) continue;
        adj[p - 1].push_back(u);
    }
    dfs(0);
    SegTree segTree(N);
    segTree.prepare();
    while (M--) {
        int a;
        cin >> a;
        if (a == 1) {
            int i; long long w;
            cin >> i >> w;
            i--;
            segTree.update(l_idx[i], r_idx[i] - 1, w);
        } else {
            int i;
            cin >> i;
            i--;
            cout << segTree.sum(l_idx[i]) << '\n';
        }
    }
}