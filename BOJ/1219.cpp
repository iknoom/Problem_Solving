#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18L;
int N, M, s, e;
bool vst[100], vst2[100];
long long dist[100], adj[100][100], adj_inv[100][100], val[100];

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

void bfs2(int e){
    vst2[e] = true;
    queue<int> q;
    q.push(e);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < N; v++){
            if(adj_inv[u][v] == INF || vst2[v]) continue;
            vst2[v] = true;
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
                if (dist[u] + adj[u][v] - val[v] < dist[v]){
                    dist[v] = dist[u] + adj[u][v] - val[v];
                }
            }
        }
    }
    for (int u = 0; u < N; u++){
        for (int v = 0; v < N; v++){
            if (adj[u][v] == INF) continue;
            if (vst[u] && vst2[u] && (dist[u] + adj[u][v] - val[v] < dist[v])){
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N >> s >> e >> M;
    for (int i = 0; i < N; i++){
        fill(adj[i], adj[i] + N, INF);
        fill(adj_inv[i], adj_inv[i] + N, INF);
    }

    for (int i = 0; i < M; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj_inv[v][u] = min(adj[v][u], w);
    }
    for (int i = 0; i < N; i++) cin >> val[i];
    bfs(s);
    bfs2(e);
    if (!vst[e]){
        cout << "gg" << '\n';
    } else {
        if (BellmanFord(s)) {
            cout << val[s] - dist[e] << '\n';
        } else {
            cout << "Gee" << '\n';
        }
    }
}