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
int board[1000][1000], dp[1000][1000][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                dp[i][j][0] = 1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cur = board[i][j];
            int before = cur ? cur - 1 : 2;
            if (j > 0) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
                }
                if (dp[i][j - 1][before] > 0) {
                    dp[i][j][cur] = max(dp[i][j][cur], dp[i][j - 1][before] + 1);
                }
            }
            if (i > 0) {
                for (int k = 0; k < 3; k++) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                }
                if (dp[i - 1][j][before] > 0) {
                    dp[i][j][cur] = max(dp[i][j][cur], dp[i - 1][j][before] + 1);
                }
            }
        }
    }
    cout << *max_element(dp[N - 1][N - 1], dp[N - 1][N - 1] + 3) << '\n';
}