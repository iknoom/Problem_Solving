#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, M, is_key[50][50], vst[50][50], p[251];
string board[50];
vector<ti> edges;

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

void bfs(int sr, int sc) {
    for (int i = 0; i < N; i++) {
        fill(vst[i], vst[i] + N, -1);
    }
    queue<pi> q;
    q.push({sr, sc});
    vst[sr][sc] = 0;
    while (!q.empty()) {
        auto[cr, cc] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = cr + dy[i], nc = cc + dx[i];
            if (nr < 0 || nr >= N) continue;
            if (nc < 0 || nc >= N) continue;
            if (vst[nr][nc] >= 0) continue;
            if (board[nr][nc] == '1') continue;
            vst[nr][nc] = vst[cr][cc] + 1;
            q.push({nr, nc});
            if (board[nr][nc] != '0') {
                edges.emplace_back(vst[nr][nc], is_key[sr][sc], is_key[nr][nc]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    // solution
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '1' || board[i][j] == '0') {
                continue;
            }
            is_key[i][j] = ++cnt;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (is_key[i][j]) {
                bfs(i, j);
            }
        }
    }

    // Kruskal
    for (int i = 1; i <= M + 1; i++) {
        p[i] = i;
    }
    sort(all(edges));
    int V = 0, all_w = 0;
    for (auto[w, u, v] : edges) {
        if (merge(u, v)) {
            all_w += w;
            V++;
        }
    }
    if (V == M) {
        cout << all_w << '\n';
    } else {
        cout << -1 << '\n';
    }
}