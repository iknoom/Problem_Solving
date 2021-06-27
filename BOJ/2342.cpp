#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
const int INF = 1e9;
int dp[5][5], next_dp[5][5];
int diff[5][5] = {
        {0, 2, 2, 2, 2},
        {0, 1, 3, 4, 3},
        {0, 3, 1, 3, 4},
        {0, 4, 3, 1, 3},
        {0, 3, 4, 3, 1}
};

int main() {
    fastio;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    while (true) {
        int cur;
        cin >> cur;
        if (cur == 0) {
            break;
        }
        // init next_dp
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                next_dp[i][j] = INF;
            }
        }
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (cur != y) {
                    next_dp[cur][y] = min(next_dp[cur][y], dp[x][y] + diff[x][cur]);
                }
                if (cur != x) {
                    next_dp[x][cur] = min(next_dp[x][cur], dp[x][y] + diff[y][cur]);
                }
            }
        }
        // next_dp -> dp
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                dp[i][j] = next_dp[i][j];
            }
        }
    }
    int answer = INF;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            answer = min(answer, dp[i][j]);
        }
    }
    cout << answer << '\n';
}