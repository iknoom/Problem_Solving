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

int main() {
    fastio;
    int R, C;
    cin >> R >> C;
    vector<string> board(R);
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }
    vector<vector<char>> nxt_board(R, vector<char>(C, '.'));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '.') continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int nr = i + dy[k], nc = j + dx[k];
                if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
                if (board[nr][nc] == 'X') cnt++;
            }
            if (cnt > 1) {
                nxt_board[i][j] = 'X';
            }
        }
    }
    int l = 0, r = C - 1, u = 0, d = R - 1;
    while (true) {
        bool flag = false;
        for (int i = 0; i < R; i++) {
            if (nxt_board[i][l] == 'X') {
                flag = true;
            }
        }
        if (flag) break;
        l++;
    }
    while (true) {
        bool flag = false;
        for (int i = 0; i < R; i++) {
            if (nxt_board[i][r] == 'X') {
                flag = true;
            }
        }
        if (flag) break;
        r--;
    }
    while (true) {
        bool flag = false;
        for (int i = 0; i < C; i++) {
            if (nxt_board[u][i] == 'X') {
                flag = true;
            }
        }
        if (flag) break;
        u++;
    }
    while (true) {
        bool flag = false;
        for (int i = 0; i < C; i++) {
            if (nxt_board[d][i] == 'X') {
                flag = true;
            }
        }
        if (flag) break;
        d--;
    }
    for (int i = u; i <= d; i++) {
        for (int j = l; j <= r; j++) {
            cout << nxt_board[i][j];
        }
        cout << '\n';
    }
}