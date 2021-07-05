#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int INF = 1e9;
int N, M, dist[400][400];

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }
    while (M--) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        dist[u][v] = min(dist[u][v], c);
    }
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    long long answer = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if (dist[i][j] < INF) {
                    answer += dist[i][j];
                }
            }
        }
    }
    cout << answer << '\n';
}