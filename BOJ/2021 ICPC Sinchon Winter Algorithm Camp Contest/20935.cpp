#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MAX = 500;
int N, M, A[MAX], B[MAX], parity[MAX], answer[2][MAX];
bool vst[MAX];
vector<pi> adj[MAX], adj_inv[MAX], left_graph[MAX];
vector<pi> path[2];

bool dfs(int u) {
    vst[u] = true;
    for (auto [v, p] : adj[u]) {
        if (B[v] == -1 || !vst[B[v]] && dfs(B[v])) {
            A[u] = v;
            B[v] = u;
            parity[u] = p;
            return true;
        }
    }
    return false;
}

int perfect_matching() {
    fill(A, A + N, -1);
    fill(B, B + N, -1);
    for (int u = 0; u < N; u++) {
        fill(vst, vst + N, false);
        if (!dfs(u)) {
            return -1;
        }
    }
    int ret = 0;
    for (int i = 0; i < N; i++) {
        ret ^= parity[i];
    }
    return ret;
}

bool bfs(int s) {
    path[0].clear();
    path[1].clear();
    path[0].resize(N, {-1, -1});
    path[1].resize(N, {-1, -1});
    queue<pi> q;
    q.push({s, 0});
    while (!q.empty()) {
        auto [u, p1] = q.front();
        q.pop();
        for (auto [v, p2] : left_graph[u]) {
            int p = p1 ^ p2;
            if (v == s) {
                if (p == 1) {
                    path[p][v] = {u, p1};
                    return true;
                }
                else continue;
            }
            if (path[p][v].first < 0) {
                path[p][v] = {u, p1};
                q.push({v, p});
            }
        }
    }
    return false;
}

int main() {
    fastio;
    // input
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w & 1);
        adj_inv[v].emplace_back(u, w & 1);
    }
    // 1. Bipartite Matching
    int p = perfect_matching();
    if (p < 0) {
        cout << -1 << '\n';
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < N; i++) {
        answer[p][i] = A[i] + 1;
        answer[p ^ 1][i] = A[i] + 1;
    }
    // 2. construct graph with left nodes
    for (int u = 0; u < N; u++) {
        for (auto [v, p] : adj_inv[A[u]]) {
            if (u == v) continue;
            left_graph[u].emplace_back(v, p ^ parity[u]);
        }
    }
    // 3. find odd cycle from left graph
    bool is_odd_cycle = false;
    for (int u = 0; u < N; u++) {
        if (bfs(u)) {
            is_odd_cycle = true;
            // swap edges
            int a = u, pa = 1;
            while (true) {
                auto [b, pb] = path[pa][a];
                answer[p ^ 1][a] = A[b] + 1;
                if (b == u) break;
                a = b;
                pa = pb;
            }
            break;
        }
    }
    // print answer
    if (is_odd_cycle){
        for (int i = 0; i < N; i++) {
            cout << i + 1 << ' ' << answer[0][i] << '\n';
        }
        for (int i = 0; i < N; i++) {
            cout <<  i + 1 << ' ' << answer[1][i] << '\n';
        }
    } else if (p == 1) {
        cout << -1 << '\n';
        for (int i = 0; i < N; i++) {
            cout <<  i + 1 << ' ' << answer[1][i] << '\n';
        }
    } else {
        for (int i = 0; i < N; i++) {
            cout <<  i + 1 << ' ' << answer[0][i] << '\n';
        }
        cout << -1 << '\n';
    }
}