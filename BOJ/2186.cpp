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
int N, M, K;
int dp[100][100][80];
vector<pi> st[26];

int main() {
    fastio;
    cin >> N >> M >> K;
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    string to_search;
    cin >> to_search;

    // solution
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            st[board[i][j] - 'A'].emplace_back(i, j);
        }
    }

    for (int i = 0; i < sz(to_search); i++) {
        if (i == 0) {
            for (auto[ci, cj] : st[to_search[i] - 'A']) {
                dp[ci][cj][i] = 1;
            }
        } else {
            for (auto[ci, cj] : st[to_search[i] - 'A']) {
                for (int k = 0; k < 4; k++) {
                    for (int l = 1; l <= K; l++) {
                        int ni = ci + dy[k] * l, nj = cj + dx[k] * l;
                        if (ni < 0 || nj < 0) continue;
                        if (ni >= N || nj >= M) continue;
                        dp[ci][cj][i] += dp[ni][nj][i - 1];
                    }
                }
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            answer += dp[i][j][sz(to_search) - 1];
        }
    }
    cout << answer << '\n';
}