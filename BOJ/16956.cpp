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
    int R, C;
    cin >> R >> C;
    vector<string> board(R);
    for (int i = 0; i < R; i++) {
        cin >> board[i];
    }
    bool flag = false;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] != 'W') continue;
            for (int k = 0; k < 4; k++) {
                int r = i + dy[k], c = j + dx[k];
                if (r < 0 || r >= R) continue;
                if (c < 0 || c >= C) continue;
                if (board[r][c] == 'S') flag = true;
            }
        }
    }
    if (flag) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == '.') cout << 'D';
                else cout << board[i][j];
            }
            cout << '\n';
        }
    }
}