#include <bits/stdc++.h>
using namespace std;

int n, k, X[3001], Y[3001];
int dp[3001][3001];
int win, lose;

int dfs(int i, int j) {
    if (dp[i][j] != 0) {
        if (dp[i][j] == 1) return dp[i][j];
        else return 0;
    }
    int ret = 0;
    int S = k, t = i;
    while (t > 0) {
        S -= X[t];
        t--;
        if (S < 0) break;
        ret += dfs(t, j);
    }

    S = k, t = j;
    while (t > 0) {
        S -= Y[t];
        t--;
        if (S < 0) break;
        ret += dfs(i, t);
    }
    if (ret == 0) {
        lose++;
        dp[i][j] = 1;
        return 1;
    }
    else {
        win++;
        dp[i][j] = 2;
        return 0;
    }
}

void solution() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> X[i];
    for (int i = 1; i <= n; i++) cin >> Y[i];
    memset(dp, 0, sizeof(dp));
    win = 0, lose = 0;
    dp[0][0] = 2;
    win++;
    dfs(n, n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << 2 - dp[j][i] << ' ';
        }
        cout << endl;
    }
    cout << win  << ' ' << lose << '\n';
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