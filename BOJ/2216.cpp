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

int main() {
    fastio;
    int A, B, C;
    cin >> A >> B >> C;
    string X, Y;
    cin >> X >> Y;
    if (X.size() < Y.size()) {
        swap(X, Y);
    }
    int N = X.size(), M = Y.size();

    int match = A - 2 * B;
    int unmatch = C - 2 * B;
    int all_blank = B * (N + M);
    vector<int> dp(N + 1);
    for (int i = 0; i < M; i++) {
        vector<int> next_dp(N + 1);
        for (int j = 0; j <= N; j++) {
            next_dp[j] = dp[j];
        }
        for (int j = 0; j < N; j++) {
            next_dp[j + 1] = max(next_dp[j + 1], next_dp[j]);
            if (X[j] == Y[i]) {
                next_dp[j + 1] = max(next_dp[j + 1], dp[j] + match);
            } else {
                next_dp[j + 1] = max(next_dp[j + 1], dp[j] + unmatch);
            }
        }
        dp = next_dp;
    }

    cout << all_blank + *max_element(all(dp)) << '\n';
}