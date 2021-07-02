#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
const int MOD = 1e6;
int N, dp[2][3][1001];
// L: 0 1
// A: 0 1 2

int main() {
    fastio;
    cin >> N;
    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int o = 0; o < 2; o++) {
            // O
            for (int a = 0; a < 3; a++) {
                // o, a -> o, 0
                dp[o][0][i] += dp[o][a][i - 1];
                dp[o][0][i] %= MOD;
            }
            // A
            for (int a = 0; a < 2; a++) {
                // o, a -> o, a + 1
                dp[o][a + 1][i] += dp[o][a][i - 1];
                dp[o][a + 1][i] %= MOD;
            }
        }
        // L
        for (int a = 0; a < 3; a++) {
            // 0, a -> 1, 0
            dp[1][0][i] += dp[0][a][i - 1];
            dp[1][0][i] %= MOD;
        }
    }
    int answer = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            answer += dp[i][j][N];
            answer %= MOD;
        }
    }
    cout << answer << '\n';
}