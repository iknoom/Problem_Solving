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
int dp[51][51][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            dp[i][j][0] = -INF;
            dp[i][j][1] = -INF;
        }
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int R_i, B_i, D_i;
        cin >> R_i >> B_i >> D_i;
        for (int a = 0; a <= 50; a++) {
            for (int b = 0; b <= 50; b++) {
                dp[a][b][i % 2] = dp[a][b][(i + 1) % 2];
                if (a - R_i >= 0 && b - B_i >= 0) {
                    dp[a][b][i % 2] = max(dp[a][b][i % 2], dp[a - R_i][b - B_i][(i + 1) % 2] + D_i);
                }
            }
        }
    }
    vector<pi> answer_list;
    for (int i = 0; i < N; i++) {
        int R_i, B_i;
        cin >> R_i >> B_i;
        answer_list.emplace_back(max(0, dp[R_i][B_i][(M + 1) % 2]), i + 1);
    }
    sort(all(answer_list));
    for (auto[v, i] : answer_list) {
        cout << i << ' ' << v << '\n';
    }
}