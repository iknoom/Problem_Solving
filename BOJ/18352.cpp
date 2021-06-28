#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int SIZE = 300001;
int N, M, K, X, level[SIZE];
vector<int> adj[SIZE];

int main() {
    fastio;
    cin >> N >> M >> K >> X;
    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    fill(level, level + N + 1, -1);
    vector<int> answer;
    queue<int> q;
    q.push(X);
    level[X] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (level[u] == K) {
            answer.push_back(u);
        }
        for (auto v : adj[u]) {
            if (level[v] >= 0) continue;
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
    if (answer.empty()) {
        cout << -1 << '\n';
    } else {
        sort(all(answer));
        for (auto u : answer) {
            cout << u << '\n';
        }
    }
}