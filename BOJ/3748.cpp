#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100000;
int V, E, dfsn[SIZE], dcnt, isLucky[SIZE], vst[SIZE];
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

void init() {
    for (int i = 0; i < V; i++) {
        adj[i].clear();
    }
    fill(dfsn, dfsn + V, 0);
    fill(isLucky, isLucky + V, 0);
    fill(vst, vst + V, -1);
    dcnt = 0;
    nodeStack.clear();
    bccList.clear();
}

void bfs(vector<pair<int, int>> &edges) {
    int s;
    for (auto[u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        s = u;
    }
    // bfs
    vst[s] = 0;
    queue<int> q;
    q.push(s);
    bool flag = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (vst[v] < 0) {
                vst[v] = vst[u] + 1;
                q.push(v);
            } else {
                int t = vst[v] + vst[u];
                if (t % 2 == 0) {
                    flag = true;
                }
            }
        }
    }
    for (auto[u, v] : edges) {
        vst[u] = -1;
        vst[v] = -1;
        adj[u].clear();
        adj[v].clear();
        if (flag) {
            isLucky[u] = 1;
            isLucky[v] = 1;
        }
    }
}

void solution() {
    cin >> V >> E;
    init();
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        if (dfsn[i] == 0) dfs(i);
    }

    for (int i = 0; i < V; i++) {
        adj[i].clear();
    }
    for (auto curBcc : bccList) {
        bfs(curBcc);
    }

    int answer = 0;
    for (int i = 0; i < V; i++) {
        if (isLucky[i]) {
            answer++;
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}