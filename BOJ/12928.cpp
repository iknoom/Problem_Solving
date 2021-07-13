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
    int N, S;
    cin >> N >> S;
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, 0));
    dp[2][0] = 1;
    for (int node_cnt = 1; node_cnt <= N - 2; node_cnt++) {
        // (n + 1)C2
        int diff = (node_cnt + 1) * node_cnt / 2;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= S; j++) {
                if (dp[i][j] && i + node_cnt <= N && j + diff <= S) {
                    dp[i + node_cnt][j + diff] = 1;
                }
            }
        }
    }
    cout << dp[N][S] << '\n';
}