#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ti = tuple<int, int, int>;
const int MOD = 1e9 + 7;
const int INF = -1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int R, C;
    cin >> R >> C;
    vector<string> board(R);
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }
    queue<ti> q;
    vector<vector<int>> vst(R, vector<int>(C, -1));
    int sr, sc, er, ec;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'X') {
                vst[i][j] = INF;
            } else if (board[i][j] == 'S') {
                sr = i; sc = j;
            } else if (board[i][j] == 'D') {
                er = i; ec = j;
            } else if (board[i][j] == '*') {
                vst[i][j] = INF;
                q.push({i, j, 1});
            }
        }
    }
    vst[sr][sc] = 0;
    q.push({sr, sc, 0});
    while (!q.empty()) {
        auto [r, c, t] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dy[i], nc = c + dx[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (vst[nr][nc] == INF) continue;
            if (vst[nr][nc] >= 0) continue;
            if (t == 0) {
                vst[nr][nc] = vst[r][c] + 1;
            } else {
                if (board[nr][nc] == 'D') continue;
                vst[nr][nc] = INF;
            }
            q.push({nr, nc, t});
        }
    }
    if (vst[er][ec] < 0) {
        cout << "KAKTUS" << '\n';
    } else {
        cout << vst[er][ec] << '\n';
    }
}