#include <bits/stdc++.h>

using namespace std;
int N, M, dp[100][100], is_r[100], is_filled[100][100];

int solve(int day, int coupon) {
    if (day >= N) {
        return 0;
    }
    if (is_filled[day][coupon]) {
        return dp[day][coupon];
    }
    int ret = 1e9;
    if (is_r[day]) {
        ret = min(ret, solve(day + 1, coupon));
    }
    if (coupon >= 3) {
        ret = min(ret, solve(day + 1, coupon - 3));
    }
    ret = min(ret, solve(day + 1, coupon) + 10000);
    ret = min(ret, solve(day + 3, coupon + 1) + 25000);
    ret = min(ret, solve(day + 5, coupon + 2) + 37000);
    is_filled[day][coupon] = 1;
    dp[day][coupon] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        is_r[k - 1] = 1;
    }
    cout << solve(0, 0) << '\n';
}