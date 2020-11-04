#include <bits/stdc++.h>
using namespace std;
const int MAX_V = 1000;
const int INF = 1e9;
typedef pair<int, int> pi;

int N, M, C;
int dist[MAX_V][1001], mooney[MAX_V];
vector<pi> adj;

int main() {
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++) cin >> mooney[i];
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj.emplace_back(u, v);
    }
    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + N, -INF);
    }
    dist[0][0] = 0;

    for (int t = 0; t < 1000; t++) {
        for (auto p : adj) {
            int u, v;
            u = p.first;
            v = p.second;
            dist[v][t + 1] = max(dist[v][t + 1], dist[u][t] + mooney[v]);
        }
    }

    int answer = 0;
    for (int t = 0; t <= 1000; t++) {
        answer = max(answer, dist[0][t] - (C * t * t));
    }

    cout << answer << '\n';
}