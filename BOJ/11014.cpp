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
const int dx[] = {-1, -1, -1, 1, 1, 1};
const int dy[] = {0, 1, -1, 0, 1, -1};
const int MAX = 7000;

int A[MAX], B[MAX], dist[MAX];
bool used[MAX];
vector<int> adj[MAX];

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
    fill(used, used + MAX, false);
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

int main() {
    fastio;
    int C;
    cin >> C;
    while (C--) {
        int N, M;
        cin >> N >> M;
        vector<string> board(N);
        for (int i = 0; i < N; i++) {
            cin >> board[i];
        }
        for (int i = 0; i < MAX; i++) {
            adj[i].clear();
        }
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 'x') continue;
                answer++;
                if (j % 2 == 1) continue;
                int cur_node = i * M + j;
                for (int k = 0; k < 6; k++) {
                    int ni = i + dy[k], nj = j + dx[k];
                    if (ni < 0 || ni >= N) continue;
                    if (nj < 0 || nj >= M) continue;
                    if (board[ni][nj] == 'x') continue;
                    int nxt_node = ni * M + nj;
                    adj[cur_node].push_back(nxt_node);
                }
            }
        }
        cout << answer - hopcroft_karp() << '\n';
    }
}