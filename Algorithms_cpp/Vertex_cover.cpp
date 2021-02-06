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

bool check_a[MAX], check_b[MAX];

void dfs_b(int x){
    if(check_a[x]) return;
    check_a[x] = true;
    for(auto i : adj[x]){
        check_b[i] = 1;
        dfs_b(B[i]);
    }
}

void getcover() {
    memset(check_a, 0, sizeof(check_a));
    memset(check_b, 0, sizeof(check_b));
    for (int i = 0; i < N; i++) if (A[i] == -1) dfs_b(i);
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

    getcover();
    vector<int> l, r;
    for (int i = 0; i < N; i++) if (!check_a[i]) l.push_back(i);
    for (int i = 0; i < M; i++) if (check_b[i]) r.push_back(i);
    cout << l.size() << ' ';
    for (auto k : l) cout << k + 1 << ' ';
    cout << '\n';
    cout << r.size() << ' ';
    for (auto k : r) cout << k + 1 << ' ';
    cout << '\n';
}