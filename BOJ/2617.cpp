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
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int bfs(int i, vector<vector<int>> &adj, int N) {
    vector<bool> vst(N);
    queue<int> q;
    vst[i] = true;
    q.push(i);
    int ret = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ret++;
        for (int v : adj[u]) {
            if (!vst[v]) {
                vst[v] = true;
                q.push(v);
            }

        }
    }
    return ret - 1;
}

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<vector<int>> lower(N, vector<int>()), higher(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        lower[u].push_back(v);
        higher[v].push_back(u);
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (bfs(i, lower, N) > N / 2) {
            answer++;
        } else if (bfs(i, higher, N) > N / 2) {
            answer++;
        }
    }
    cout << answer << '\n';
}