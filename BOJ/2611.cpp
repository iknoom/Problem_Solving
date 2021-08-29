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
int N, M, vst[1000], prv[1000], dp[1000];
vector<pi> adj[1000];
vector<int> ts;

void dfs(int u) {
    vst[u] = 1;
    for (auto[v, w] : adj[u]) {
        if (vst[v]) continue;
        dfs(v);
    }
    ts.push_back(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
    }
    dfs(0);
    reverse(all(ts));
    fill(prv, prv + N, -1);
    for (auto u : ts) {
        for (auto[v, w] : adj[u]) {
            if (dp[v] < dp[u] + w) {
                dp[v] = dp[u] + w;
                prv[v] = u;
            }
        }
    }
    cout << dp[0] << '\n';
    vector<int> answer;
    int u = 0;
    while (true) {
        answer.push_back(u + 1);
        u = prv[u];
        if (u == 0) {
            answer.push_back(u + 1);
            break;
        }
    }
    reverse(all(answer));
    for (auto k : answer) cout << k << ' ';
    cout << '\n';
}