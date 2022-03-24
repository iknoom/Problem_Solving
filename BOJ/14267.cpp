#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> inc(N);
    vector<vector<int>> p(N);
    for (int i = 0; i < N; i++) {
        int j;
        cin >> j;
        if (j < 0) {
            continue;
        }
        p[j - 1].push_back(i);
    }
    for (int i = 0; i < M; i++) {
        int u, w;
        cin >> u >> w;
        inc[u - 1] += w;
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : p[u]) {
            inc[v] += inc[u];
            q.push(v);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << inc[i] << ' ';
    }
    cout << '\n';
}