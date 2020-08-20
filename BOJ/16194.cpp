#include <bits/stdc++.h>

using namespace std;
int N, dp[1005], P[1005];
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = 1e9;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j] + P[j]);
        }
    }

    cout << dp[N] << endl;

}