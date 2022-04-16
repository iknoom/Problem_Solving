#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
const long long INF = 1e18;
// int N, K, prv[100000][201];
// long long dp[100000][2];
int N, K, prv[200][100000];
long long dp[2][100000];

struct line {
    long long a, b, px, py;
    int idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // input
    cin >> N >> K;
    vector<long long> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        if (i > 0) {
            S[i] += S[i - 1];
        }
    }
    // fill dp[i][k]
    for (int i = 0; i < N - 1; i++) {
        dp[i][1] = S[i] * (S.back() - S[i]);
    }
    // fill dp[i][k]
    for (int k = 2; k <= K; k++) {
        vector<line> line_stack;
        line_stack.push_back({-1, 0, -1000000000, 1});
        int fpos = 0;
        for (int i = 0; i < N - 1; i++) {
            // next_dp[i] = a * S[i] + b
            if (!line_stack.empty()) {
                while (fpos + 1 < sz(line_stack) && line_stack[fpos + 1].px <= S[i] * line_stack[fpos + 1].py) {
                    fpos++;
                }
                dp[i][k % 2] = line_stack[fpos].a * S[i] + line_stack[fpos].b - S[i] * (S[i] - S.back());
                prv[i][k] = line_stack[fpos].idx;
            } else {
                dp[i][k % 2] = 0;
            }

            // push line
            long long a = S[i];
            long long b = dp[i][(k % 2) ^ 1] - S[i] * S.back();
            if (a == line_stack.back().a) {
                if (b > line_stack.back().b) {
                    line_stack.pop_back();
                } else {
                    continue;
                }
            }
            while (true) {
                // get point
                long long cx, cy;
                cx = line_stack.back().b - b;
                cy = a - line_stack.back().a;
                if (line_stack.back().px * cy >= cx * line_stack.back().py) {
                    line_stack.pop_back();
                } else {
                    line_stack.push_back({a, b, cx, cy, i});
                    break;
                }
            }
        }
    }

    // get answer
    long long max_value = -INF;
    int max_idx = -1;
    for (int i = 0; i < N; i++) {
        if (max_value < dp[i][K % 2]) {
            max_value = dp[i][K % 2];
            max_idx = i;
        }
    }
    cout << max_value << '\n';
    vector<int> answer;
    int idx = max_idx;
    for (int k = K; k > 0; k--) {
        answer.push_back(idx + 1);
        idx = prv[idx][k];
    }
    reverse(all(answer));
    for (auto k : answer) {
        cout << k << ' ';
    }
    cout << '\n';
}