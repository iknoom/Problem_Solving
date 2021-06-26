#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;


int bfs(int s, int e, vector<vector<int>> &adj) {
    vector<int> level(100, -1);
    deque<int> q;
    level[s] = 0;
    q.push_back(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        if (u == e) {
            return level[e];
        }
        if (adj[u].empty()) {
            // 주사위
            for (int jump = 1; jump <= 6; jump++) {
                int v = u + jump;
                if (v < 100 && level[v] < 0) {
                    level[v] = level[u] + 1;
                    if (adj[v].empty()) {
                        q.push_back(v);
                    } else {
                        q.push_front(v);
                    }

                }
            }
        }
        else {
            // 사다리, 뱀
            for (int v : adj[u]) {
                if (level[v] < 0) {
                    level[v] = level[u];
                    q.push_back(v);
                }
            }
        }
    }
}

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(100);
    for (int i = 0; i < N + M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    cout << bfs(0, 99, adj) << '\n';
}