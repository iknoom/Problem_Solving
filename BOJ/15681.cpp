#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MAX = 1e5;
int N, R, Q, vst[MAX], cnt[MAX];
vector<int> adj[MAX];

void dfs(int u){
    vst[u] = 1;
    cnt[u] = 1;
    for (int v : adj[u]) {
        if (vst[v]) continue;
        dfs(v);
        cnt[u] += cnt[v];
    }
}

int main() {
    fastio;
    cin >> N >> R >> Q;
    R--;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(R);
    while (Q--) {
        int u;
        cin >> u;
        u--;
        cout << cnt[u] << '\n';
    }
}