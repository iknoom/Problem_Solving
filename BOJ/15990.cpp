#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 9;
long long dp[3][100001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    dp[0][1] = 1;
    dp[1][2] = 1;
    dp[2][3] = 1;
    for (int i = 1; i <= 100000; i++) {
        for (int a = 1; a <= 3; a++) {
            if (i - a < 0) continue;
            for (int b = 1; b <= 3; b++) {
                if (a == b) continue;
                dp[a - 1][i] += dp[b - 1][i - a];
            }
            dp[a - 1][i] %= MOD;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << (dp[0][n] + dp[1][n] + dp[2][n]) % MOD << '\n';
    }
}