#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
long long dp[11][111][111][111];

int main() {
    fastio;
    int N, R, G, B;
    cin >> N >> R >> G >> B;
    vector<long long> factorial;
    factorial.push_back(1);

    for (int i = 1; i <= N; i++) {
        factorial.push_back(factorial.back() * i);
    }

    dp[0][0][0][0] = 1;
    long long all = 0;
    for (int n = 1; n <= N; n++) {
        all += n;
        // 1가지
        for (int i = 0; i <= R; i++) {
            for (int j = 0; j <= G; j++) {
                for (int k = 0; k <= B; k++) {
                    dp[n][i + n][j][k] += dp[n - 1][i][j][k];
                    dp[n][i][j + n][k] += dp[n - 1][i][j][k];
                    dp[n][i][j][k + n] += dp[n - 1][i][j][k];
                }
            }
        }

        // 2가지
        if (n % 2 == 0) {
            long long cnt = factorial[n] / factorial[n/2] / factorial[n/2];
            for (int i = 0; i <= R; i++) {
                for (int j = 0; j <= G; j++) {
                    for (int k = 0; k <= B; k++) {
                        dp[n][i + n/2][j + n/2][k] += dp[n - 1][i][j][k] * cnt;
                        dp[n][i + n/2][j][k + n/2] += dp[n - 1][i][j][k] * cnt;
                        dp[n][i][j + n/2][k + n/2] += dp[n - 1][i][j][k] * cnt;
                    }
                }
            }
        }

        // 3가지
        if (n % 3 == 0) {
            long long cnt = factorial[n] / factorial[n/3] / factorial[n/3] / factorial[n/3];
            for (int i = 0; i <= R; i++) {
                for (int j = 0; j <= G; j++) {
                    for (int k = 0; k <= B; k++) {
                        dp[n][i + n/3][j + n/3][k + n/3] += dp[n - 1][i][j][k] * cnt;
                    }
                }
            }
        }
    }

    long long answer = 0;
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= G; j++) {
            for (int k = 0; k <= B; k++) {
                if (i + j + k == all) {
                    answer += dp[N][i][j][k];
                }
            }
        }
    }
    cout << answer << '\n';
}