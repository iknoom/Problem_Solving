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

void solution() {
    int K, M, P;
    cin >> K >> M >> P;
    vector<int> cnt(M, 0);
    vector<vector<int>> adj(M, vector<int>());
    while (P--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        cnt[v]++;
    }
    queue<int> q;
    vector<vector<int>> before(M, vector<int>());
    vector<int> dp(M, 0);
    for (int i = 0; i < M; i++) {
        if (cnt[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (before[u].empty()) {
            dp[u] = 1;
        } else {
            int max_val, c = 0;
            max_val = *max_element(all(before[u]));
            for (auto k : before[u]) {
                if (k == max_val) c++;
            }
            if (c > 1) {
                dp[u] = max_val + 1;
            } else {
                dp[u] = max_val;
            }
        }
        for (auto v : adj[u]) {
            before[v].push_back(dp[u]);
            cnt[v]--;
            if (cnt[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << K << ' ' << dp[M - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solution();
    }
}