#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N, M, W;
int dist[501], adj[501][501];

bool BellmanFord(int s){
    fill(dist, dist + N, INF);
    dist[s] = 0;
    for (int loop = 0; loop < N - 1; loop++){
        for (int u = 0; u < N; u++){
            for (int v = 0; v < N; v++){
                if (adj[u][v] == INF) continue;
                if (dist[u] + adj[u][v] < dist[v]){
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }
    for (int u = 0; u < N; u++){
        for (int v = 0; v < N; v++){
            if (dist[u] + adj[u][v] < dist[v]){
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M >> W;
        for (int i = 0; i < N; i++){
            fill(adj[i], adj[i] + N, INF);
        }
        for (int i = 0; i < M; i++){
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            adj[u][v] = min(adj[u][v], w);
            adj[v][u] = min(adj[v][u], w);
        }
        for (int i = 0; i < W; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            adj[u][v] = min(adj[u][v], -w);
        }

        if (BellmanFord(0)) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}