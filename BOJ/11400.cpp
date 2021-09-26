#include <bits/stdc++.h>

using namespace std;
const int SIZE = 100000;
int V, E, low[SIZE], order[SIZE], cnt;
vector<int> adj[SIZE];

void dfs(int u, int p, vector<pair<int, int>> &ret) {
    low[u] = order[u] = ++cnt;
    for (auto v : adj[u]) {
        if (v == p) {
            continue;
        }
        if (order[v] > 0) {
            low[u] = min(low[u], order[v]);
            continue;
        }
        dfs(v, u, ret);
        if (low[v] > order[u]) {
            ret.push_back({min(u, v), max(u, v)});
        }
        low[u] = min(low[u], low[v]);
    }
}

vector<pair<int, int>> getArticulationBridge() {
    vector<pair<int, int>> ret;
    for (int i = 0; i < V; i++) {
        if (order[i]) continue;
        dfs(i, -1, ret);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<pair<int, int>> answer = getArticulationBridge();
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (auto [u, v] : answer) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}