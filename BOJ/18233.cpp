#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

using pi = pair<long long, long long>;
const long long INF = 1e18;

long long dist[5000];
int V, E, P, found[5000];
vector<pi> adj[5000];
vector<int> prv[5000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E >> P;
    P--;
    for (int i = 0; i < E; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }
    fill(dist, dist + V, INF);

    priority_queue<pi, vector<pi>, greater<>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        auto[_, u] = pq.top();
        pq.pop();
        if (found[u]) {
            continue;
        }
        found[u] = 1;
        for (auto[v, w] : adj[u]) {
            if (found[v]) {
                continue;
            }
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prv[v].clear();
                prv[v].push_back(u);
                pq.push({dist[v], v});
            } else if (dist[v] == dist[u] + w) {
                prv[v].push_back(u);
            }
        }
    }

    queue<int> q;
    vector<bool> vst(5000, false);
    q.push(V - 1);
    vst[V - 1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : prv[u]) {
            if (vst[v]) continue;
            vst[v] = true;
            q.push(v);
        }
    }
    if (vst[P]) {
        cout << "SAVE HIM" << '\n';
    } else {
        cout << "GOOD BYE" << '\n';
    }
}