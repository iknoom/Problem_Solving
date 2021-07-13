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
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, M, vst[1000];
vector<pi> adj[1000];

int dfs(int u) {
    vst[u] = 1;
    int ret = 0;
    for (auto[v, w] : adj[u]) {
        if (vst[v]) continue;
        ret += min(w, dfs(v));
    }
    if (ret == 0) {
        return INF;
    } else {
        return ret;
    }
}

void solution() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        adj[i].clear();
        vst[i] = 0;
    }
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    if (N == 1) {
        cout << 0 << '\n';
    } else {
        cout << dfs(0) << '\n';
    }
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}