#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100000;
int V, E, dfsn[SIZE], dcnt;
vector<int> adj[SIZE];
vector<pair<int, int>> nodeStack;
vector<vector<pair<int, int>>> bccList;

int dfs(int u, int prv = -1) {
    int ret = dfsn[u] = ++dcnt;
    for (int v : adj[u]) {
        if (v == prv) {
            continue;
        }
        if (dfsn[u] > dfsn[v]) {
            nodeStack.push_back({u, v});
        }
        if (dfsn[v] > 0) {
            ret = min(ret, dfsn[v]);
        } else {
            int tmp = dfs(v, u);
            ret = min(ret, tmp);
            if (tmp >= dfsn[u]) {
                vector<pair<int, int>> curBcc;
                while (!nodeStack.empty() && nodeStack.back() != make_pair(u, v)) {
                    curBcc.push_back(nodeStack.back());
                    nodeStack.pop_back();
                }
                curBcc.push_back(nodeStack.back());
                nodeStack.pop_back();
                bccList.push_back(curBcc);
            }
        }
    }
    return ret;
}

vector<int> getArticulationPoints() {
    for (int i = 0; i < V; i++) {
        if (dfsn[i] == 0) dfs(i);
    }
    vector<int> ret, cnt(V);
    for (auto &curBcc : bccList) {
        set<int> bccNodes;
        for (auto [u, v] : curBcc) {
            bccNodes.insert(u);
            bccNodes.insert(v);
        }
        for (auto u : bccNodes) {
            cnt[u]++;
        }
    }
    for (int i = 0; i < V; i++) {
        if (cnt[i] > 1) {
            ret.push_back(i);
        }
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
    vector<int> answer = getArticulationPoints();
    cout << answer.size() << '\n';
    for (auto u : answer) {
        cout << u + 1 << ' ';
    }
}