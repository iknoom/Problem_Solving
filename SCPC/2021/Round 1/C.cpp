#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

bool bfs(int s, int e, vector<vector<int>> &adj, int N) {
    vector<bool> vst(N);
    queue<int> q;
    vst[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == e) return true;
        for (int v : adj[u]) {
            if (vst[v]) continue;
            vst[v] = true;
            q.push(v);
        }
    }
    return false;
}

void solution() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> adj(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    for (int i = 0; i < K; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (bfs(v, u, adj, N)) {
            swap(u, v);
            cout << 1;
        } else {
            cout << 0;
        }
        adj[u].push_back(v);
    }
    cout << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << '\n';
        solution();
    }
}