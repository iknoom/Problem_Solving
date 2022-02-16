#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, 1};
const int dy[] = {0, 0, 1, 1};
int board[128][128], cnt;

enum {
    LeftTop, RightTop, LeftBottom, RightBottom
};

void fill_board(int x0, int y0, int l, int t) {
    if (l == 2) {
        cnt++;
        for (int i = 0; i < 4; i++) {
            if (i == t) continue;
            board[y0 + dy[i]][x0 + dx[i]] = cnt;
        }
        return;
    }
    fill_board(x0 + l/4, y0 + l/4, l/2, t);
    if (t != LeftTop) {
        fill_board(x0, y0, l/2, RightBottom);
    }
    if (t != RightTop) {
        fill_board(x0 + l/2, y0, l/2, LeftBottom);
    }
    if (t != LeftBottom) {
        fill_board(x0, y0 + l/2, l/2, RightTop);
    }
    if (t != RightBottom) {
        fill_board(x0 + l/2, y0 + l/2, l/2, LeftTop);
    }
}

void solve(int x0, int y0, int l, int hx, int hy) {
    if (l == 1) {
        board[y0][x0] = -1;
        return;
    }
    int t = -1;
    if (hx < x0 + l/2 && hy < y0 + l/2) {
        // 1
        solve(x0, y0, l/2, hx, hy);
        t = LeftTop;
    } else if (hx >= x0 + l/2 && hy < y0 + l/2) {
        // 2
        solve(x0 + l/2, y0, l/2, hx, hy);
        t = RightTop;
    } else if (hx < x0 + l/2 && hy >= y0 + l/2) {
        // 3
        solve(x0, y0 + l/2, l/2, hx, hy);
        t = LeftBottom;
    } else {
        // 4
        solve(x0 + l/2, y0 + l/2, l/2, hx, hy);
        t = RightBottom;
    }
    fill_board(x0, y0, l, t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int K, x, y, L;
    cin >> K;
    cin >> x >> y;
    x--; y--;
    L = pow(2, K);
    solve(0, 0, L, x, y);
    for (int i = L - 1; i >= 0; i--) {
        for (int j = 0; j < L; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}