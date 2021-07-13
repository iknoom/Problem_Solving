#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dr[] = {-2, -2, 0, 0, 2, 2};
const int dc[] = {-1, 1, -2, 2, -1, 1};

int main() {
    fastio;
    int N;
    cin >> N;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    vector<vector<int>> vst(N, vector<int>(N, -1));
    vst[r1][c1] = 0;
    queue<pi> q;
    q.push({r1, c1});
    while (!q.empty()) {
        auto[r, c] = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= N) continue;
            if (nc < 0 || nc >= N) continue;
            if (vst[nr][nc] >= 0) continue;
            vst[nr][nc] = vst[r][c] + 1;
            q.push({nr, nc});
        }
    }
    cout << vst[r2][c2] << '\n';
}