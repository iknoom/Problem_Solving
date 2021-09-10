#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<long long, int, long long>;
const long long INF = 1e18;

int N, M;
long long fuel[2500], dist[2500][2501], found[2500][2501];
vector<pi> adj[2500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> fuel[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }
    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + 2501, INF);
    }
    priority_queue<ti, vector<ti>, greater<>> pq;
    pq.push({0, 0, fuel[0]});
    dist[0][fuel[0]] = 0;
    while (!pq.empty()) {
        auto[_, u, f] = pq.top();
        pq.pop();
        if (found[u][f]) {
            continue;
        }
        found[u][f] = 1;
        if (f > fuel[u]) {
            if (dist[u][fuel[u]] <= dist[u][f]) {
                continue;
            }
            dist[u][fuel[u]] = dist[u][f];
            f = fuel[u];
        }
        for (auto [v, w] : adj[u]) {
            if (found[v][f]) {
                continue;
            }
            if (dist[v][f] > dist[u][f] + f * w) {
                dist[v][f] = dist[u][f] + f * w;
                pq.push({dist[v][f], v, f});
            }
        }
    }
    long long answer = INF;
    for (int i = 0; i <= 2500; i++) {
        answer = min(answer, dist[N - 1][i]);
    }
    cout << answer << '\n';
}