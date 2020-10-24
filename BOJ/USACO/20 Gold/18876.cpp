#include <bits/stdc++.h>

using namespace std;



vector<int> get_prime(int N) {
    vector<int> prime;
    vector<int> is_prime(N + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = 2; j * i <= N; j++) {
                is_prime[j * i] = 0;
            }
        }
    }
    return prime;
}



int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> prime = get_prime(N);

    vector<long long> dp(N + 1, 0);
    dp[0] = 1;
    for (auto p : prime) {
        vector<long long> inc(N + 1, 0);
        long long cur = p;
        while (cur <= N) {
            for (long long i = cur; i <= N; i++) {
                inc[i] += dp[i - cur] * cur;
                inc[i] %= M;
            }
            cur *= p;
        }
        for (int i = 0; i < N + 1; i++) {
            dp[i] += inc[i];
        }
    }

    long long ans = 0;
    for (auto k : dp) {
        ans += k;
        ans %= M;
    }
    cout << ans << '\n';
}