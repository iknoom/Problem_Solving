#include <bits/stdc++.h>
using namespace std;
int N, K, vst[100000], dp[100000][21], dp2[100000][21], answer;
vector<int> adj[100000];

void dfs(int u) {
    vst[u] = 1;
    dp[u][0] = 1;
    for (auto v : adj[u]) {
        if (vst[v]) {
            continue;
        }
        dfs(v);
        for (int i = 1; i <= K; i++) {
            dp[u][i] += dp[v][i - 1];
        }
    }
}

void dfs2(int u, int p) {
    vst[u] = 1;
    for (int i = 0; i <= K; i++) {
        dp2[u][i] = dp[u][i];
    }
    if (p >= 0) {
        for (int i = 1; i <= K; i++) {
            dp[u][i] += dp[p][i - 1];
            if (i >= 2) {
                dp[u][i] -= dp2[u][i - 2];
            }
        }
    }
    int ret = 0;
    for (int i = 0; i <= K; i++) {
        ret += dp[u][i];
    }
    answer = max(answer, ret);
    for (auto v : adj[u]) {
        if (vst[v]) {
            continue;
        }
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    fill_n(vst, N, 0);
    dfs2(0, -1);
    cout << answer << '\n';
}