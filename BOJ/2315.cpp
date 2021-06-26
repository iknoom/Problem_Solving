#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<long long, long long>;
const long long INF = 1e18;
int N, M;
long long dp[1000][1000][2];
vector<pi> T;

vector<int> solution() {
    // init
    M--;
    int L = M, R = N - M - 1;
    for (int l = 0; l <= L; l++) {
        for (int r = 0; r <= R; r++) {
            dp[l][r][0] = dp[l][r][1] = INF;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0;
    // construct prefix sum
    vector<long long> prefix_sum;
    prefix_sum.push_back(0);
    for (int i = 0; i < N; i++) {
        prefix_sum.push_back(prefix_sum.back() + T[i].y);
    }
    // fill dp
    for (int l = 0; l <= L; l++) {
        for (int r = 0; r <= R; r++) {
            long long d, w;
            // to left: dp[l][r][0]
            if (l > 0) {
                // w: sum(l - 1, r)
                w = prefix_sum.back() - (prefix_sum[M + r + 1] - prefix_sum[M - l + 1]);
                d = T[M - l + 1].x - T[M - l].x; // l - 1 -> l
                dp[l][r][0] = min(dp[l][r][0], dp[l - 1][r][0] + d * w);
                d = T[M + r].x - T[M - l].x; // r -> l
                dp[l][r][0] = min(dp[l][r][0], dp[l - 1][r][1] + d * w);
            }
            // to right: dp[l][r][1]
            if (r > 0) {
                // w: sum(l, r - 1)
                w = prefix_sum.back() - (prefix_sum[M + r] - prefix_sum[M - l]);
                d = T[M + r].x - T[M - l].x; // l -> r
                dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][0] + d * w);
                d = T[M + r].x - T[M + r - 1].x; // r - 1 -> r
                dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][1] + d * w);
            }
        }
    }
    return min(dp[L][R][0], dp[L][R][1]);
}

int main() {
    fastio;
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        long long D, W;
        cin >> D >> W;
        T.emplace_back(D, W);
    }
    // solution
    if (M == 1) {
        long long answer = 0;
        for (int i = 0; i < N; i++) {
            answer += (T[i].x - T[0].x) * T[i].y;
        }
        cout << answer << '\n';
    } else if (M == N) {
        long long answer = 0;
        for (int i = 0; i < N; i++) {
            answer += (T[N - 1].x - T[i].x) * T[i].y;
        }
        cout << answer << '\n';
    } else {
        long long answer = solution();
        cout << answer << '\n';
    }
}