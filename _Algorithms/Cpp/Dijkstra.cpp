#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 20000;
const int INF = 1e9;
typedef pair<int, int> pi;

vector<pi> adj[MAX_V];
int dist[MAX_V];

void dijkstra(int s) {
    bool found[MAX_V] = {false};
    priority_queue<pi, vector<pi>, greater<pi>> PQ;

    fill(dist, dist+MAX_V, INF);
    dist[s] = 0;
    PQ.push(pi(0, s));

    while(!PQ.empty()){
        int u = PQ.top().second;
        PQ.pop();
        if (found[u]) continue;
        found[u] = true;
        for(auto v: adj[u]){
            int next = v.first, d = v.second;
            if(dist[next] > dist[u] + d){
                dist[next] = dist[u] + d;
                PQ.push(pi(dist[next], next));
            }
        }
    }
}

int main() {
    int V, E, start;
    cin >> V >> E >> start;
    for (int i=0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(pi(v, w));
    }
    start--;
    dijkstra(start);
}