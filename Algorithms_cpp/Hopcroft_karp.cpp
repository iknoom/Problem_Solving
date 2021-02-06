#include <bits/stdc++.h>

using namespace std;
const int MAX = 10000;
const int INF = 1000000000;

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
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        while (k--) {
            int b;
            cin >> b;
            adj[i].push_back(b - 1);
        }
    }
    cout << hopcroft_karp() << '\n';
}