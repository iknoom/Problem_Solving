#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int N, M, T, board[100][100][2], vst[100][100][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j][0];
            vst[i][j][0] = vst[i][j][1] = -1;
        }
    }

    queue<ti> q;
    q.push({0, 0, 0});
    vst[0][0][0] = 0;
    int answer = -1;
    while (!q.empty()) {
        auto[r, c, t] = q.front();
        q.pop();
        if (r == N - 1 && c == M - 1) {
            answer = vst[r][c][t];
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dy[i], nc = c + dx[i];
            if (nr < 0 || nr >= N) continue;
            if (nc < 0 || nc >= M) continue;
            if (vst[nr][nc][t] >= 0) continue;
            if (board[nr][nc][t] == 1) continue;
            if (board[nr][nc][t] == 2) {
                if (vst[nr][nc][t + 1] >= 0) continue;
                vst[nr][nc][t + 1] = vst[r][c][t] + 1;
                q.push({nr, nc, t + 1});
            } else {
                vst[nr][nc][t] = vst[r][c][t] + 1;
                q.push({nr, nc, t});
            }
        }
    }
    if (answer < 0 || answer > T) {
        cout << "Fail" << '\n';
    } else {
        cout << answer << '\n';
    }

}