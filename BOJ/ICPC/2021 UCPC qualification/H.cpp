#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using pi = pair<int, long long>;
const int SIZE = 100000;
int N, M, K, S, T, vst[SIZE];
long long dp[11][SIZE];
vector<pi> adj[SIZE];
vector<pi> adj_inv[SIZE];
vector<int> ts;

void dfs(int u) {
    vst[u] = 1;
    for (auto [v, t] : adj[u]) {
        if (vst[v]) continue;
        dfs(v);
    }
    ts.push_back(u);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K >> S >> T;
    for (int i = 0; i < M; i++) {
        int u, v; long long t;
        cin >> u >> v >> t;
        u--; v--;
        adj[u].emplace_back(v, t);
        adj_inv[v].emplace_back(u, t);
    }
    // ts
    for (int i = 0; i < N; i++) {
        if (vst[i]) continue;
        dfs(i);
    }
    reverse(ts.begin(), ts.end());

    // fill dp
    S--; T--;
    for (int k = 0; k <= K; k++) {
        for (int i = 0; i < N; i++) {
            dp[k][i] = -1;
        }
    }
    dp[0][S] = 0;
    for (int k = 0; k <= K; k++) {
        for (auto u : ts) {
            if (dp[k][u] < 0) continue;
            for (auto [v, w] : adj[u]) {
                dp[k][v] = max(dp[k][v], dp[k][u] + w);
            }
            if (k == K) continue;
            for (auto [v, w] : adj_inv[u]) {
                dp[k + 1][v] = max(dp[k + 1][v], dp[k][u]);
            }
        }
    }


    long long answer = -1;
    for (int k = 0; k <= K; k++) {
        answer = max(answer, dp[k][T]);
    }
    cout << answer << '\n';
}