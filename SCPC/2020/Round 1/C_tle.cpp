#include <bits/stdc++.h>
using namespace std;

int N, k, m, dp[1501][1501];
using pi = pair<int, int>;

void debug() {
    /*
    * 1 2 3 4
    * 2 1 3 4
    * 2 3 1 4
    * 2 3 4 1
    * 4 3 2 1
    * 4 1 2 3
    * 3 1 2 4
    */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << dp[i][j] << ' ';
        cout << endl;
    }
}

void solution() {
    cin >> N >> k >> m;
    vector<pi> rows;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        rows.emplace_back(a, b);
    }

    for (int i = 0; i < N; i++)
        fill(dp[i], dp[i] + N, -1e9);

    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (auto p : rows) {
            int a = p.first, b = p.second;
            int x = dp[i][a] + 1;
            int y = dp[i][b] + 1;
            dp[i][a] = max(dp[i][a], y);
            dp[i][b] = max(dp[i][b], x);
            for (int j = 0; j < N; j++) {
                if (j != a && j != b) {
                    dp[i][j]++;
                }
            }
        }
    }
    // debug();

    int ans = 0;
    while (m--) {
        int i, j;
        cin >> i >> j;
        i--; j--;
        if (dp[i][j] < 0) ans--;
        else ans += k - dp[i][j];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T, test_case;

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cout << "Case #" << test_case+1 << endl;
        solution();
    }
    return 0;
}