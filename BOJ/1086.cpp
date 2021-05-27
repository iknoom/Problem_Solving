#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;

long long dp[1 << 15][100];
int N, K, ten[1000];
bool vst[1 << 15];
vector<string> string_set;

void bfs() {
    queue<pi> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [bit_set, len] = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if ((bit_set & (1 << i))) {
                continue;
            }
            int next_bit = (bit_set | (1 << i));
            // get mod K value
            int r = 0, l = string_set[i].size();
            for (int j = 0; j < l; j++) {
                r += (string_set[i][l - 1 - j] - '0') * ten[len + j] % K;
            }
            // update dp
            for (int j = 0; j < K; j++) {
                int next_r = (j + r) % K;
                dp[next_bit][next_r] += dp[bit_set][j];
            }
            // push queue
            if (!vst[next_bit]) {
                vst[next_bit] = true;
                q.push({next_bit, len + string_set[i].size()});
            }
        }
    }
}

void init() {
    ten[0] = 1;
    for (int i = 1; i < 1000; i++) {
        ten[i] = ten[i - 1] * 10 % K;
    }
    dp[0][0] = 1;
}

int main() {
    // input
    cin >> N;
    string_set.resize(N);
    for (int i = 0; i < N; i++) cin >> string_set[i];
    cin >> K;

    // init
    init();

    // solution
    bfs();

    long long all_case = 0, zero_case, g;
    for (int i = 0; i < K; i++) {
        all_case += dp[(1 << N) - 1][i]; // N!
    }
    zero_case = dp[(1 << N) - 1][0];
    g = gcd(zero_case, all_case);
    if (zero_case == 0) {
        cout << "0/1" << '\n';
    } else {
        cout << zero_case/g << '/' << all_case/g << '\n';
    }
}


