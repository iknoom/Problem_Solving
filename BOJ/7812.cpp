#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<long long, long long>;
const long long INF = 1e18;

int n;
long long children[10000], dist[10000], answer;
bool vst[10000];

void dfs(int u, vector<vector<pi>> &adj) {
    vst[u] = true;
    for (auto [v, w] : adj[u]) {
        if (vst[v]) continue;
        dfs(v, adj);
        children[u] += children[v];
        dist[u] += dist[v] + w * children[v];
    }
}

void dfs2(int u, long long from, vector<vector<pi>> &adj) {
    vst[u] = true;
    answer = min(answer, from + dist[u]);
    for (auto [v, w] : adj[u]) {
        if (vst[v]) continue;
        long long sub = dist[u] - dist[v] - w * children[v];
        dfs2(v, from + sub + w * (n - children[v]),adj);
    }
}

void solution() {
    fill(children, children + n, 1);
    fill(dist, dist + n, 0);
    answer = INF;

    vector<vector<pi>> adj(n, vector<pi>());
    for (int i = 0; i < n - 1; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    fill(vst, vst + n, false);
    dfs(0, adj);
    fill(vst, vst + n, false);
    dfs2(0, 0, adj);

    cout << answer << '\n';
}

int main() {
    fastio;
    while (true) {
        cin >> n;
        if (n == 0) break;
        if (n == 1) cout << 0 << '\n';
        else solution();
    }
}