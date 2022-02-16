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
    string s;
    cin >> s;
    vector<int> dp(sz(s), -INF);
    dp[0] = s[0] == '+' ? 10 : 1;
    if (s[0] == '+' && s[1] == '-') {
        dp[1] = 11;
    }
    for (int i = 2; i < sz(s); i++) {
        int k = s[i] == '+' ? 10 : 1;
        if (s[i - 1] == '+') {
            dp[i] = max(dp[i], dp[i - 2] + k);
        } else {
            dp[i] = max(dp[i], dp[i - 2] - k);
        }
        if (i > 2 && s[i] == '-' && s[i - 1] == '+') {
            if (s[i - 2] == '+') {
                dp[i] = max(dp[i], dp[i - 3] + 11);
            } else {
                dp[i] = max(dp[i], dp[i - 3] - 11);
            }
        }
    }
    cout << dp[sz(s) - 1] << '\n';
}