#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAX_D = 17;
int N, Q;
int depth[30001];
int p[30001][MAX_D];
vector<int> adj[30001];


void get_depth() {
    queue<pi> q;
    vector<bool> vst(N, false);
    q.push({ 0, 0 });
    vst[0] = true;
    while (!q.empty()) {
        int u, cnt;
        tie(u, cnt) = q.front();
        q.pop();
        depth[u] = cnt;
        for (auto v : adj[u]) {
            if (!vst[v]) {
                vst[v] = true;
                p[v][0] = u;
                q.push({ v, cnt + 1 });
            }
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    for (int j = MAX_D - 1; j >= 0; j--) {
        if (diff >= (1 << j)) {
            u = p[u][j];
            diff -= (1 << j);
        }
    }

    if (u == v) return u;

    for (int j = MAX_D - 1; j >= 0; j--) {
        if (p[u][j] != p[v][j]) {
            u = p[u][j];
            v = p[v][j];
        }
    }
    return p[u][0];
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    memset(p, -1, sizeof(p));
    get_depth();

    for (int j = 1; j < MAX_D; j++) {
        for (int i = 0; i < N; i++) {
            if (p[i][j - 1] != -1)
                p[i][j] = p[ p[i][j - 1] ][j - 1];
        }
    }

    cin >> Q;
    int cur = 0;
    long long ans = 0;
    while (Q--) {
        int next, c;
        cin >> next;
        next -= 1;
        c = LCA(cur, next);
        ans += depth[cur] + depth[next] - 2 * depth[c];
        cur = next;
    }
    cout << ans << '\n';
}