#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
using tt = tuple<int, int, int>;

int N, M, b[10], answer_edges[9], selected_edges[9], min_value;
vector<tt> edges;

int find(vector<int> &p, int u) {
    if (p[u] == u) return u;
    return p[u] = find(p, p[u]);
}

bool merge(vector<int> &p, int u, int v) {
    u = find(p, u);
    v = find(p, v);
    if (u == v) return false;
    p[u] = v;
    return true;
}

int degree_bounded_mst() {
    int ret = 0;
    vector<int> degree(N), p(N);
    for (int i = 0; i < N; i++) p[i] = i;
    for (int i = 0; i < N - 1; i++) {
        auto [u, v, w] = edges[selected_edges[i]];
        degree[u - 1]++;
        degree[v - 1]++;
        if (!merge(p, u - 1, v - 1)) return INF;
        ret += w;
    }
    // is Degree Bounded?
    for (int i = 0; i < N; i++) {
        if (degree[i] > b[i]) {
            return INF;
        }
    }
    return ret;
}

void combination(int s, int selected_i) {
    if (selected_i == N - 1) {
        int value = degree_bounded_mst();
        if (value < min_value) {
            min_value = value;
            for (int i = 0; i < N - 1; i++) {
                answer_edges[i] = selected_edges[i];
            }
        }
        return;
    }
    for (int i = s; i < M; i++) {
        selected_edges[selected_i] = i;
        combination(i + 1, selected_i + 1);
    }
}

int main() {
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> b[i];
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }

    // init
    min_value = INF;

    // solution
    combination(0, 0);
    if (N == 1 && M == 0) {
        cout << "YES" << '\n';
    } else if (min_value == INF) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (int i = 0; i < N - 1; i++) {
            auto [u, v, w] = edges[answer_edges[i]];
            cout << u << ' ' << v << '\n';
        }
    }
}