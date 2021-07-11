#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MAX = 300;
const int INF = 1e9;
int N, M, A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> adj[MAX];

void bfs() {
    queue<int> Q;
    for (int i = 0; i < N; i++) {
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
        for (int i = 0; i < N; i++)
            if (!used[i] && dfs(i)) flow++;
        if (flow == 0) break;
        match += flow;
    }
    return match;
}
int main() {
    fastio;
    int Q;
    cin >> N >> M >> Q;
    set<pi> S;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        S.insert({u - 1, v - 1});
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S.find({i, j}) == S.end()) {
                adj[i].push_back(j);
            }
        }
    }
    cout << hopcroft_karp() << '\n';
}