#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N, dp[2000000], cost[20][20];

void dfs(int depth) {
    if (depth == N - 1) {
        for (int i = 0; i < N; i++) {
            dp[1 << i] = cost[depth][i];
        }
        return;
    }
    dfs(depth + 1);
    for (int bits = 0; bits < (1 << N); bits++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if ((1 << i) & bits) {
                cnt++;
            }
        }
        if (cnt != N - depth - 1) {
            continue;
        }
        for (int i = 0; i < N; i++) {
            dp[bits | (1 << i)] = min(dp[bits | (1 << i)], dp[bits] + cost[depth][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }
    fill_n(dp, (1 << N), INF);
    dfs(0);
    cout << dp[(1 << N) - 1] << '\n';
}