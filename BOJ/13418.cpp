#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, M, p[1001];

int find(int u) {
    if (p[u] == u) return u;
    p[u] = find(p[u]);
    return p[u];
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        p[u] = v;
        return true;
    }
    return false;
}

int get_mst(vector<ti> &edges) {
    for (int i = 0; i <= N; i++) {
        p[i] = i;
    }
    int ret = 0;
    for (auto[w, u, v] : edges) {
        if (merge(u, v)) {
            ret += w;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    vector<ti> edges;
    for (int i = 0; i < M + 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(1 - w, u, v);
    }
    sort(all(edges));
    long long min_mst = get_mst(edges);
    sort(all(edges), greater<>());
    long long max_mst = get_mst(edges);
    cout << max_mst * max_mst - min_mst * min_mst << '\n';
}