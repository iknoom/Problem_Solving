#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int n, m, vst[5000], sccn[5000], cnt;
vector<int> adj[5000], adj_inv[5000], st;

void dfs(int u) {
    vst[u] = 1;
    for (auto v : adj[u]) {
        if (vst[v]) continue;
        dfs(v);
    }
    st.push_back(u);
}

void dfs_inv(int u) {
    vst[u] = 1;
    sccn[u] = cnt;
    for (auto v : adj_inv[u]) {
        if (vst[v]) continue;
        dfs_inv(v);
    }
}

void init() {
    st.clear();
    cnt = 0;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        adj_inv[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> n;
        if (n == 0) break;
        cin >> m;
        init();
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj_inv[v].push_back(u);
        }

        // ts
        fill(vst, vst + n, 0);
        for (int i = 0; i < n; i++) {
            if (vst[i]) continue;
            dfs(i);
        }

        // dfs inv
        fill(vst, vst + n, 0);
        reverse(all(st));
        for (auto u : st) {
            if (vst[u]) continue;
            dfs_inv(u);
            cnt++;
        }

        vector<bool> is_bottom(cnt, true);
        for (int u = 0; u < n; u++) {
            for (auto v : adj[u]) {
                if (sccn[u] != sccn[v]) {
                    is_bottom[sccn[u]] = false;
                }
            }
        }

        for (int u = 0; u < n; u++) {
            if (is_bottom[sccn[u]]) {
                cout << u + 1 << ' ';
            }
        }
        cout << '\n';
    }
}