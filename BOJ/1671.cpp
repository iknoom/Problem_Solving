#include <bits/stdc++.h>

using namespace std;
const int MAX = 300;
const int INF = 1e9;

int N, A[MAX], B[MAX], dist[MAX];
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
        match += flow;
    }
    return match;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (i == j) continue;
        if ((a[i] == a[j]) && (b[i] == b[j]) && (c[i] == c[j])) {
            if (i < j) continue;
            adj[i * 2].push_back(j);
            adj[i * 2 + 1].push_back(j);
        } else if ((a[i] >= a[j]) && (b[i] >= b[j]) && (c[i] >= c[j])) {
            adj[i * 2].push_back(j);
            adj[i * 2 + 1].push_back(j);
        }
    }
    N *= 2;
    cout << N/2 - hopcroft_karp() << '\n';
}