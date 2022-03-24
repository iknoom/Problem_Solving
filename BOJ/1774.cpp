#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
using ti = tuple<double, int, int>;
int N, M, is_connected[1000][1000], p[1000];
vector<pi> points;

double get_dist(int i, int j) {
    double dx = abs(points[i].x - points[j].x);
    double dy = abs(points[i].y - points[j].y);
    return sqrt(dx * dx + dy * dy);
}

vector<ti> get_edges(int N) {
    vector<ti> edges;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (is_connected[i][j]) {
                edges.emplace_back(0, i, j);
            } else {
                edges.emplace_back(get_dist(i, j), i, j);
            }
        }
    }
    return edges;
}

int find(int u) {
    if (p[u] == u) {
        return u;
    }
    return p[u] = find(p[u]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return false;
    } else {
        p[u] = v;
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    points.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u > v) swap(u, v);
        is_connected[u][v] = 1;
    }

    // solution
    iota(p, p + N, 0);
    vector<ti> edges = get_edges(N);
    sort(all(edges));
    double answer = 0;
    for (auto[w, u, v] : edges) {
        if (merge(u, v)) {
            answer += w;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << answer << '\n';
}