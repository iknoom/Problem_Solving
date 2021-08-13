#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, K, board[200][200], S, X, Y;

int main() {
    fastio;
    cin >> N >> K;
    vector<ti> v;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] > 0) {
                v.emplace_back(board[i][j], i, j);
            }
        }
    }
    cin >> S >> X >> Y;
    X--; Y--;
    sort(all(v));
    queue<pi> q;
    for (auto [_, r, c] : v) {
        q.push({r, c});
    }
    while (S--) {
        int q_size = sz(q);
        while (q_size--) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dy[i], nc = c + dx[i];
                if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
                if (board[nr][nc] > 0) continue;
                board[nr][nc] = board[r][c];
                q.push({nr, nc});
            }
        }
    }
    cout << board[X][Y] << '\n';
}