#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    // 플로이드 워샬
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int answer = INF;
    pi answer_pair = {-1, -1};
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int cur = 0;
            for (int k = 0; k < N; k++) {
                cur += min(dist[k][i], dist[k][j]);
            }
            if (answer > cur * 2) {
                answer = cur * 2;
                answer_pair = {i + 1, j + 1};
            }
        }
    }
    cout << answer_pair.x << ' ' << answer_pair.y << ' ' << answer << '\n';
}