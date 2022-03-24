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
int N, dp[100000][2], vst[100000], p[100000], answer;
vector<int> adj[100000];

void dfs(int u) {
    vst[u] = 1;
    vector<int> ret(2);
    for (auto v : adj[u]) {
        if (vst[v]) continue;
        p[v] = u;
        dfs(v);
        ret.push_back(dp[v][0] + 1);
    }
    sort(all(ret), greater<>());
    dp[u][0] = ret[0];
    dp[u][1] = ret[1];
}

void dfs2(int u, int before) {
    vst[u] = 1;
    vector<int> ret(2);
    ret.push_back(before);
    for (auto v : adj[u]) {
        if (vst[v]) continue;
        if (dp[v][0] + 1 == dp[u][0]){
            dfs2(v, max(before, dp[u][1]) + 1);
        } else {
            dfs2(v, max(before, dp[u][0]) + 1);
        }
        ret.push_back(dp[v][0] + 1);
    }
    sort(all(ret), greater<>());
    if (ret[0] > 0 && ret[1] > 0 && ret[2] > 0) {
        answer = max(answer, ret[0] + ret[1] + ret[2] + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill_n(p, N, -1);
    dfs(0);
    fill_n(vst, N, 0);
    dfs2(0, 0);
    cout << answer << '\n';
}