#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18L;
int N, M;
bool vst[501];
long long dist[501], adj[501][501];

void bfs(int s){
    vst[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < N; v++){
            if(adj[u][v] == INF || vst[v]) continue;
            vst[v] = true;
            q.push(v);
        }
    }
}

bool BellmanFord(int s){
    fill(dist, dist + N, INF);
    dist[s] = 0L;
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
            if (vst[u] && dist[u] + adj[u][v] < dist[v]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N >> M;

    for (int i = 0; i < N; i++){
        fill(adj[i], adj[i] + N, INF);
    }
    for (int i = 0; i < M; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u][v] = min(adj[u][v], w);
    }

    bfs(0);

    if (BellmanFord(0)){
        for (int i = 1; i < N; i++){
            if (!vst[i] || dist[i] == INF){
                cout << -1 << '\n';
            }
            else {
                cout << dist[i] << '\n';
            }
        }
    }
    else {
        cout << -1 << '\n';
    }
}