#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
int N, M, C, dp[100000], cnt[100000];
vector<pi> adj[100000];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++) cin >> dp[i];
    for (int i = 0; i < C; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        cnt[v]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto p : adj[u]) {
            int v, w;
            v = p.first; w = p.second;
            dp[v] = max(dp[v], dp[u] + w);
            cnt[v]--;
            if (cnt[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dp[i] << '\n';
    }
}