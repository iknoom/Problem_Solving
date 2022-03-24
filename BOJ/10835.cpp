#include <bits/stdc++.h>

using namespace std;
int N, A[2000], B[2000], dp[2000][2000];

int solve(int i, int j) {
    if (i == -1 || j == -1) {
        return 0;
    }
    if (dp[i][j] >= 0) {
        return dp[i][j];
    }
    int ret = max(solve(i - 1, j - 1), solve(i - 1, j));
    if (A[i] > B[j]) {
        ret = max(ret, solve(i, j - 1) + B[j]);
    }
    dp[i][j] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = N - 1; i >= 0; i--) {
        cin >> A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        fill_n(dp[i], N, -1);
    }
    cout << solve(N - 1, N - 1) << '\n';
}