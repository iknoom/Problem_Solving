#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ti = tuple<int, int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int N, M, K;
vector<ti> board[50][50], tmp[50][50];

int main() {
    fastio;
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        r--; c--;
        board[r][c].emplace_back(m, s, d);
    }
    while (K--) {
        // board -> tmp
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (auto [m, s, d] : board[i][j]) {
                    int nr = (i + dy[d] * s) % N;
                    int nc = (j + dx[d] * s) % N;
                    if (nr < 0) nr += N;
                    if (nc < 0) nc += N;
                    tmp[nr][nc].emplace_back(m, s, d);
                }
                board[i][j].clear();
            }
        }
        // tmp -> board
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int all = sz(tmp[i][j]);
                if (all == 1) {
                    board[i][j].push_back(tmp[i][j].back());
                } else if (all > 1) {
                    int d_sum = 0, s_sum = 0, m_sum = 0;
                    for (auto [m, s, d] : tmp[i][j]) {
                        d_sum += d % 2;
                        s_sum += s;
                        m_sum += m;
                    }
                    int cur_m = m_sum / 5;
                    int cur_s = s_sum / all;
                    if (cur_m > 0) {
                        int cur_d;
                        if (d_sum == 0 || d_sum == all) {
                            cur_d = 0;
                        } else {
                            cur_d = 1;
                        }
                        for (; cur_d < 8; cur_d += 2) {
                            board[i][j].emplace_back(cur_m, cur_s, cur_d);
                        }
                    }
                }
                tmp[i][j].clear();
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (auto [m, s, d] : board[i][j]) {
                answer += m;
            }
        }
    }
    cout << answer << '\n';
}