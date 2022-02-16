#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, T;
    cin >> N >> T;
    vector<pi> studies(N);
    for (int i = 0; i < N; i++) {
        cin >> studies[i].x >> studies[i].y;
    }
    vector<int> dp(T + 1);
    for (int i = 0; i < N; i++) {
        vector<int> next_dp(T + 1);
        for (int j = 0; j <= T; j++) {
            next_dp[j] = dp[j];
            if (j - studies[i].x >= 0) {
                next_dp[j] = max(next_dp[j], dp[j - studies[i].x] + studies[i].y);
            }
        }
        dp = next_dp;
    }
    cout << dp[T] << '\n';
}