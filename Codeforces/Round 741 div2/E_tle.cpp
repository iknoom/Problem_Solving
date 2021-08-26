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

void solution() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = n - i;
        for (int j = 0; j < i; j++) {
            if (S[j] < S[i]) {
                dp[i] = max(dp[i], dp[j] + (n - i));
            } else if (S[j] == S[i]) {
                int k = 0;
                while (i + k < n && S[j + k] == S[i + k]) {
                    k++;
                }
                if (i + k >= n) {
                    continue;
                }
                if (S[j + k] < S[i + k]) {
                    dp[i] = max(dp[i], dp[j] + (n - i) - k);
                }
            }
        }
    }

    cout << *max_element(all(dp)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        solution();
    }
}