#include <bits/stdc++.h>
using namespace std;
int N, board[20][20];

enum {
    ROWCUT, COLCUT, ROWCOLCUT
};

pair<int, int> count_star_dust(int x0, int y0, int x1, int y1) {
    int star = 0, dust = 0;
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            if (board[y][x] == 2) star++;
            if (board[y][x] == 1) dust++;
        }
    }
    return {star, dust};
}

int solve(int x0, int y0, int x1, int y1, int rc) {
    auto [all_star, all_dust] = count_star_dust(x0, y0, x1, y1);
    if (all_star == 1 && all_dust == 0) {
        return 1;
    }
    int ret = 0;
    if (rc != ROWCUT) {
        for (int x = x0 + 1; x < x1; x++) {
            auto [star, dust] = count_star_dust(x, y0, x, y1);
            if (star != 0) continue;
            if (dust == 0) continue;
            int l = solve(x0, y0, x - 1, y1, ROWCUT);
            int r = solve(x + 1, y0, x1, y1, ROWCUT);
            ret += l * r;
        }
    }
    if (rc != COLCUT) {
        for (int y = y0 + 1; y < y1; y++) {
            auto [star, dust] = count_star_dust(x0, y, x1, y);
            if (star != 0) continue;
            if (dust == 0) continue;
            int l = solve(x0, y0, x1, y - 1, COLCUT);
            int r = solve(x0, y + 1, x1, y1, COLCUT);
            ret += l * r;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int answer = solve(0, 0, N - 1, N - 1, ROWCOLCUT);
    if (answer == 0) {
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }
}