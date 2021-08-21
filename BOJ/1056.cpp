#include <bits/stdc++.h>

using namespace std;
const long long INF = 2e18;

map<long long, long long> dp;

long long my_pow(long long x, long long n) {
    long long ret = 1;
    for (int i = 0; i < n; i++) {
        if (ret > INF / x) {
            return INF;
        }
        ret *= x;
    }
    return ret;
}

long long get_ceil_log(long long n, long long base) {
    long long l = 1, r = 1e9;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if (my_pow(mid, base) >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

long long solve(long long n) {
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }
    long long ret = n - 1;
    for (int i = 2; i < 100; i++) {
        long long x = get_ceil_log(n, i);
        ret = min(ret, solve(x) + abs(n - my_pow(x, i)) + 1);
        if (x == 2) break;
        long long y = x - 1;
        ret = min(ret, solve(y) + abs(n - my_pow(y, i)) + 1);
    }
    dp[n] = ret;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    long long n;
    cin >> n;
    cout << solve(n) << '\n';
}