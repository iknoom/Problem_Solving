#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
const long long MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
const int ddx[] = {2, 2, -2, -2};
const int ddy[] = {2, -2, 2, -2};
long long N, M, L, _L, dp[300][300][50];
vector<pi> pos[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> _L;

    string to_search;
    cin >> to_search;
    L = (int)to_search.size();

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < M; j++) {
            pos[board[i][j] - 'A'].emplace_back(i, j);
        }
    }

    // solution for L == 1
    if (L == 1) {
        cout << (int)pos[to_search[0] - 'A'].size() << '\n';
        return 0;
    }

    // solution
    long long all_diff = 0;
    vector<long long> row_diff(N), col_diff(M);
    for (int i = 0; i < L - 1; i++) {
        long long nxt_all_diff = 0;
        vector<long long> nxt_row_diff(N), nxt_col_diff(M);
        for (auto[r, c] : pos[to_search[i] - 'A']) {
            if (i == 0) {
                dp[r][c][i] = 1;
            }
            // Add before diff
            dp[r][c][i] += all_diff;
            dp[r][c][i] %= MOD;
            dp[r][c][i] += row_diff[r];
            dp[r][c][i] %= MOD;
            dp[r][c][i] += col_diff[c];
            dp[r][c][i] %= MOD;

            // Update all diff
            nxt_all_diff += dp[r][c][i];
            nxt_all_diff %= MOD;
            // Update row diff
            for (auto nr : {r - 1, r, r + 1}) {
                if (nr < 0 || nr >= N) continue;
                nxt_row_diff[nr] += MOD - dp[r][c][i];
                nxt_row_diff[nr] %= MOD;
            }
            // Update col diff
            for (auto nc : {c - 1, c, c + 1}) {
                if (nc < 0 || nc >= M) continue;
                nxt_col_diff[nc] += MOD - dp[r][c][i];
                nxt_col_diff[nc] %= MOD;
            }
            // Update 3 * 3 square
            for (int k = 0; k < 9; k++) {
                int nr = r + dy[k], nc = c + dx[k];
                if (nr < 0 || nr >= N) continue;
                if (nc < 0 || nc >= M) continue;
                dp[nr][nc][i + 1] += dp[r][c][i];
                dp[nr][nc][i + 1] %= MOD;
            }
            // Update 4 points
            for (int k = 0; k < 4; k++) {
                int nr = r + ddy[k], nc = c + ddx[k];
                if (nr < 0 || nr >= N) continue;
                if (nc < 0 || nc >= M) continue;
                dp[nr][nc][i + 1] += MOD - dp[r][c][i];
                dp[nr][nc][i + 1] %= MOD;
            }
        }
        all_diff = nxt_all_diff;
        row_diff = nxt_row_diff;
        col_diff = nxt_col_diff;
    }

    long long answer = 0;
    for (auto[r, c] : pos[to_search[L - 1] - 'A']) {
        dp[r][c][L - 1] += all_diff;
        dp[r][c][L - 1] %= MOD;
        dp[r][c][L - 1] += row_diff[r];
        dp[r][c][L - 1] %= MOD;
        dp[r][c][L - 1] += col_diff[c];
        dp[r][c][L - 1] %= MOD;
        answer += dp[r][c][L - 1];
        answer %= MOD;
    }
    cout << answer << '\n';
}