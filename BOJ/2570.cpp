#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int MAX = 5000;
int N, M, A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> adj[MAX];

int color1[100][100], color2[100][100];

void bfs() {
    queue<int> Q;
    for (int i = 0; i < MAX; i++) {
        if (!used[i]) {
            dist[i] = 0;
            Q.push(i);
        } else dist[i] = INF;
    }
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        for (int b: adj[a]) {
            if (B[b] != -1 && dist[B[b]] == INF) {
                dist[B[b]] = dist[a] + 1;
                Q.push(B[b]);
            }
        }
    }
}

bool dfs(int a) {
    for (int b: adj[a]) {
        if (B[b] == -1 || (dist[B[b]] == dist[a] + 1 && dfs(B[b]))) {
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}

int hopcroft_karp() {
    int match = 0;
    fill(A, A + MAX, -1);
    fill(B, B + MAX, -1);
    while (1) {
        bfs();
        int flow = 0;
        for (int i = 0; i < MAX; i++)
            if (!used[i] && dfs(i)) flow++;
        if (flow == 0) break;
        match += flow;
    }
    return match;
}

bool is_ok(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

int main() {
    fastio;
    cin >> N >> M;
    while (M--) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        color1[r][c] = -1;
        color2[r][c] = -1;
    }

    vector<pi> v;
    for (int i = 0; i < N; i++) v.emplace_back(0, i);
    for (int i = 1; i < N; i++) v.emplace_back(i, 0);
    int cnt = 1;
    for (auto[r, c] : v) {
        while (is_ok(r, c)) {
            if (color1[r][c] < 0) {
                cnt++;
            } else {
                color1[r][c] = cnt;
            }
            r++;c++;

        }
        cnt++;
    }
    v.clear();
    for (int i = 0; i < N; i++) v.emplace_back(0, i);
    for (int i = 1; i < N; i++) v.emplace_back(i, N - 1);
    cnt = 1;
    for (auto[r, c] : v) {
        while (is_ok(r, c)) {
            if (color1[r][c] < 0) {
                cnt++;
            } else {
                color2[r][c] = cnt;
            }
            r++;c--;

        }
        cnt++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (color1[i][j] < 0) continue;
            adj[color1[i][j]].push_back(color2[i][j]);
        }
    }
    cout << hopcroft_karp() << '\n';
}