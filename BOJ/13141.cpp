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
int N, M, max_edge[200][200], dist[200][200];


int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
        max_edge[u][v] = max(max_edge[u][v], w);
        max_edge[v][u] = max(max_edge[v][u], w);
    }
    // floyd-warshall
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    double answer = INF;
    for (int start = 0; start < N; start++) {
        double cur = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[start][i] < dist[start][j]) {
                    continue;
                }
                double diff = max_edge[i][j] - (dist[start][i] - dist[start][j]);
                cur = max(cur, (double)dist[start][i] + (diff / 2));
            }
        }
        answer = min(answer, cur);
    }
    cout << fixed;
    cout.precision(1);
    cout << answer << '\n';
}