#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MAX_V = 1000;
vector<pi> adj[MAX_V];

int dist[MAX_V], prv[MAX_V];

void dijkstra(int s) {
    bool found[MAX_V] = {false};
    priority_queue<pi, vector<pi>, greater<pi>> PQ;

    fill(dist, dist+MAX_V, INF);
    fill(prv, prv+MAX_V, -1);
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
                prv[next] = u;
                PQ.push(pi(dist[next], next));
            }
        }
    }
}

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
    }
    int s, e;
    cin >> s >> e;
    s--; e--;
    dijkstra(s);
    cout << dist[e] << '\n';
    vector<int> path;
    int cur = e;
    while (cur >= 0) {
        path.push_back(cur + 1);
        cur = prv[cur];
    }
    cout << sz(path) << '\n';
    reverse(all(path));
    for (auto k : path) {
        cout << k << ' ';
    }
    cout << '\n';
}