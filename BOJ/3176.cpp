#include <bits/stdc++.h>

using namespace std;

using pi = pair<int, int>;

const int MAXN = 100001;
const int MAX_PSIZE = 20;

int n, depth[MAXN];
int p[MAXN][MAX_PSIZE], max_w[MAXN][MAX_PSIZE], min_w[MAXN][MAX_PSIZE];
vector<pi> adj[MAXN];
bool vst[MAXN];

void dfs(int u, int depth) {
    vst[u] = true, depth[u] = depth;
    for (auto vw : adj[u]){
        int v = vw.first;
        int w = vw.second;
        if (!vst[v]) {
            p[v][0] = u;
            max_w[v][0] = w;
            min_w[v][0] = w;
            dfs(v, depth + 1);
        }
    }
}

void construct_lca() {
    for (int j = 1; j < MAX_PSIZE; j++)
        for (int i = 1; i <= n; i++) {
            p[i][j] = p[p[i][j - 1]][j - 1];
            max_w[i][j] = max(max_w[i][j - 1], max_w[p[i][j - 1]][j - 1]);
            min_w[i][j] = min(min_w[i][j - 1], min_w[p[i][j - 1]][j - 1]);
        }
}

void find_lca(int a, int b) {
    // Make a have a higher depth
    if (depth[a] < depth[b]) swap(a, b);

    // Elevate a to the depth of b
    int depth_diff = depth[a] - depth[b], ret_min, ret_max;
    ret_min = 1e9;
    ret_max = -1e9;
    for (int j = MAX_PSIZE - 1; j >= 0; j--) {
        if (depth_diff & (1 << j)) {
            ret_min = min(ret_min, min_w[a][j]);
            ret_max = max(ret_max, max_w[a][j]);
            a = p[a][j];
        }
    }
    if (a == b) {
        cout << ret_min << ' ' << ret_max << '\n';
        return;
    }

    for (int j = MAX_PSIZE - 1; j >= 0; j--) {
        if (p[a][j] != p[b][j]) {
            ret_min = min(ret_min, min_w[a][j]);
            ret_max = max(ret_max, max_w[a][j]);
            ret_min = min(ret_min, min_w[b][j]);
            ret_max = max(ret_max, max_w[b][j]);
            a = p[a][j], b = p[b][j];
        }
    }
    ret_min = min(ret_min, min_w[a][0]);
    ret_max = max(ret_max, max_w[a][0]);
    ret_min = min(ret_min, min_w[b][0]);
    ret_max = max(ret_max, max_w[b][0]);
    cout << ret_min << ' ' << ret_max << '\n';
}
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }

    dfs(0, 0);
    max_w[0][0] = -1e9;
    min_w[0][0] = 1e9;
    construct_lca();

    int K;
    cin >> K;
    while (K--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        find_lca(u, v);
    }
}