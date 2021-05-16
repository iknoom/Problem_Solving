#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int solution() {
    int N;
    cin >> N;
    vector<int> dp(N + 1, 0);
    dp[N] = 1;
    for (int i = N; i > 1; i--) {
        if(!dp[i]) continue;
        int s = 2;
        if (i == N) s = 3;
        for (int p = s; p * p <= i; p++) {
            if (i % p == 0) {
                int q = i / p;
                if (p > 2) dp[p - 1] = max(dp[p - 1], dp[i] + 1);
                if (q > 2) dp[q - 1] = max(dp[q - 1], dp[i] + 1);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N + 1; i++) {
        answer = max(answer, dp[i]);
    }
    return answer;
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cout << "Case #" << c << ": " << solution() << '\n';
    }
}