#include <bits/stdc++.h>

using namespace std;
const int MOD = 998244353;
int dp[200001][450];

void fillDp() {
    dp[0][0] = 1;
    for (int i = 0; i <= 200000; i++) {
        for (int j = 1; j < 450; j++) {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
            if (i - j >= 0) {
                dp[i][j] += dp[i - j][j];
                dp[i][j] %= MOD;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fillDp();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int answer = 0;
        for (int i = 1; i * i <= n; i++) {
            int r = n - i * i;
            if (r % 2 == 1) continue;
            answer += dp[r / 2][i];
            answer %= MOD;
        }
        cout << answer << '\n';
    }
}