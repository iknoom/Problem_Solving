#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
const int MAX = 200000;
int N, C, l_idx[MAX], r_idx[MAX], cnt;
long long depth[MAX];
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

void dfs(int u, int d) {
    l_idx[u] = cnt++;
    depth[u] = d;
    for (int v : adj[u]) {
        if (l_idx[v] < 0) {
            dfs(v, d + 1);
        }
    }
    r_idx[u] = cnt;
}

int main() {
    fastio;
    cin >> N >> C;
    C--;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    fill(l_idx, l_idx + N, -1);
    dfs(C, 0);
    SegTree segTree(N);
    segTree.prepare();
    int Q;
    cin >> Q;
    while (Q--) {
        int a, u;
        cin >> a >> u;
        u--;
        if (a == 1) {
            segTree.update(l_idx[u], 1);
        } else {
            cout << segTree.sum(l_idx[u], r_idx[u] - 1) * (depth[u] + 1) << '\n';
        }
    }
}