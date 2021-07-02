#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, M, vst[50][50], finished[50][50], dp[50][50];
string board[50];

bool is_ok(int x, int y) {
    return (0 <= x && x < M && 0 <= y && y < N);
}

bool dfs(int x, int y) {
    vst[y][x] = 1;
    int diff = board[y][x] - '0';
    int cur_dp = 1;
    for (int i = 0; i < 4; i++) {
        int x1 = x + dx[i] * diff, y1 = y + dy[i] * diff;
        if (!is_ok(x1, y1)) {
            continue;
        }
        if (board[y1][x1] == 'H') {
            continue;
        }
        if (vst[y1][x1]){
            if (finished[y1][x1]) {
                cur_dp = max(cur_dp, dp[y1][x1] + 1);
                continue;
            } else {
                return true;
            }
        }
        if (dfs(x1, y1)) {
            return true;
        }
        cur_dp = max(cur_dp, dp[y1][x1] + 1);
    }
    dp[y][x] = cur_dp;
    finished[y][x] = 1;
    return false;
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    // cycle
    if (dfs(0, 0)) {
        cout << -1 << '\n';
    } else {
        cout << dp[0][0] << '\n';
    }

}