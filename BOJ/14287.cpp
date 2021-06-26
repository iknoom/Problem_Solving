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
            segTree.update(l_idx[i], w);
        } else {
            int i;
            cin >> i;
            i--;
            cout << segTree.sum(l_idx[i], r_idx[i] - 1) << '\n';
        }
    }
}