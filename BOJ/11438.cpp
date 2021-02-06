#include <bits/stdc++.h>

using namespace std;
const int MAX_D = 17;
const int MAXN = 100000;

int N, Q, p[MAXN][MAX_D], depth[MAXN];
vector<int> adj[MAXN];
bool vst[MAXN];

void dfs(int i, int d) {
    vst[i] = true, depth[i] = d;
    for (int j : adj[i])
        if (!vst[j]) {
            p[j][0] = i;
            dfs(j, d + 1);
        }
}

void construct_lca() {
    dfs(0, 0);
    for (int j = 1; j < MAX_D; j++)
        for (int i = 1; i < N; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
}

int find_lca(int a, int b) {
    // Make a have a higher depth
    if (depth[a] < depth[b]) swap(a, b);

    // Elevate a to the depth of b
    int depth_diff = depth[a] - depth[b];
    for (int j = MAX_D - 1; j >= 0; j--)
        if (depth_diff & (1 << j))
            a = p[a][j];

    if (a == b) return a;

    for (int j = MAX_D - 1; j >= 0; j--)
        if (p[a][j] != p[b][j])
            a = p[a][j], b = p[b][j];

    return p[a][0];
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y), adj[y].push_back(x);
    }
    construct_lca();

    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        cout << find_lca(u, v) + 1 << '\n';
    }
}