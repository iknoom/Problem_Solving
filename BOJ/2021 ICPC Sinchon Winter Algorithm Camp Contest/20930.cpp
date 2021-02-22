#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using tt = tuple<int, int, int>;

int find(vector<int> &p, int u) {
    if (p[u] == u) return u;
    return p[u] = find(p, p[u]);
}

bool merge(vector<int> &p, int u, int v) {
    u = find(p, u);
    v = find(p, v);
    if (u == v) return true;
    p[u] = v;
    return false;
}

int main() {
    fastio;
    // input
    int N, Q;
    cin >> N >> Q;
    vector<tt> x_sweep, y_sweep;
    for (int i = 0; i < N; i++) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        if (x0 > x1) swap(x0, x1);
        if (y0 > y1) swap(y0, y1);
        x_sweep.emplace_back(x0, x1, i);
        y_sweep.emplace_back(y0, y1, i);
    }

    // Sweeping & Union-Find
    vector<int> p(N);
    for (int i = 0; i < N; i++) p[i] = i;
    sort(all(x_sweep));
    sort(all(y_sweep));
    for (auto sweep : {x_sweep, y_sweep}) {
        int before = -1, end_point = -1;
        for (auto [s, e, i] : sweep) {
            if (before < 0 || end_point < s) {
                before = i;
                end_point = e;
            } else {
                merge(p, i, before);
                end_point = max(end_point, e);
            }
        }
    }

    // Query
    while (Q--) {
        int u, v;
        cin >> u >> v;
        cout << int(find(p, u - 1) == find(p, v - 1)) << '\n';
    }
}