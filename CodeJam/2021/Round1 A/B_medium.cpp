#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

void solution() {
    int M, S = 0;
    cin >> M;
    vector<int> primes;
    for (int i = 0; i < M; i++) {
        int p, n;
        cin >> p >> n;
        while (n--) primes.push_back(p);
    }
    int N = 60000;
    vector<int> dp(N, -1);
    dp[1] = 0;
    for (int k = 0; k < primes.size(); k++) {
        int prime = primes[k];
        S += prime;
        vector<int> next_dp(N, -1);
        for (int i = 0; i < N; i++) next_dp[i] = dp[i];
        for (int i = 0; i < N; i++) {
            if (dp[i] < 0) continue;
            if (i * prime < N) {
                next_dp[i * prime] = dp[i] + prime;
            }
        }
        for (int i = 0; i < N; i++) dp[i] = next_dp[i];
    }
    // get answer
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] < 0) {
            continue;
        }
        if (dp[i] + i == S) {
            ret = max(ret, i);
        }
    }
    cout << ret << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cout << "Case #" << c << ": ";
        solution();
    }
}