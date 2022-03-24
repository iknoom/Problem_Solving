#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
const int INF = 1e9;

vector<int> solve(vector<vector<int>> &mid, int i, int j) {
    vector<int> ret;
    if (mid[i][j] < 0) {
        ret.push_back(i);
    } else {
        vector<int> left = solve(mid, i, mid[i][j]);
        vector<int> right = solve(mid, mid[i][j], j);
        ret.insert(ret.end(), all(left));
        ret.insert(ret.end(), all(right));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    vector<vector<int>> mid(N, vector<int>(N, -1));
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = min(dist[u][v], w);
    }
    // floyd
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    mid[i][j] = k;
                }
            }
        }
    }
    // 1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (dist[i][j] != INF ? dist[i][j] : 0) << ' ';
        }
        cout << '\n';
    }
    // 2
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == i || dist[i][j] == INF) {
                cout << 0 << '\n';
            } else {
                vector<int> path = solve(mid, i, j);
                cout << sz(path) + 1<< ' ';
                for (auto k : path) {
                    cout << k + 1 << ' ';
                }
                cout << j + 1 << '\n';
            }
        }
    }
}