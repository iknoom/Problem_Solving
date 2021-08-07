#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int N, K;
long long arr[600][600], prefix[600][600], left_prefix[600][600], right_prefix[600][600];

void make_prefix_sum() {
    for (int x = 0; x < N; x++) {
        prefix[0][x] = arr[0][x];
        left_prefix[0][x] = arr[0][x];
        right_prefix[0][x] = arr[0][x];
    }
    for (int y = 1; y < N; y++) {
        for (int x = 0; x < N; x++) {
            prefix[y][x] = prefix[y - 1][x] + arr[y][x];

            if (x > 0) {
                right_prefix[y][x] = right_prefix[y - 1][x - 1] + arr[y][x];
            } else {
                right_prefix[y][x] = arr[y][x];
            }

            if (x < N - 1) {
                left_prefix[y][x] = left_prefix[y - 1][x + 1] + arr[y][x];
            } else {
                left_prefix[y][x] = arr[y][x];
            }
        }
    }
}

long long get_prefix_sum(int x, int l, int r) {
    if (x < 0 || x >= N) return 0;
    if (r < 0) return 0;
    if (l >= N) return 0;
    r = min(r, N - 1);
    l = max(0, l);
    if (l == 0) return prefix[r][x];
    return prefix[r][x] - prefix[l - 1][x];

}

long long get_left_prefix_sum(int ex, int ey, int len) {
    if (len <= 0) return 0;
    int sx = ex + len - 1;
    int sy = ey - len + 1;

    if (ex < 0) {
        int diff = -ex;
        ex += diff;
        ey -= diff;
    }
    if (ey >= N) {
        int diff = ey - (N - 1);
        ex += diff;
        ey -= diff;
    }
    if (sx >= N) {
        int diff = sx - (N - 1);
        sx -= diff;
        sy += diff;
    }
    if (sy < 0) {
        int diff = -sy;
        sx -= diff;
        sy += diff;
    }
    if (ex >= N || ey < 0) return 0;
    if (sx < 0 || sy >= N) return 0;
    if (sx == N - 1 || sy == 0) return left_prefix[ey][ex];
    return left_prefix[ey][ex] - left_prefix[sy - 1][sx + 1];
}

long long get_right_prefix_sum(int ex, int ey, int len) {
    if (len <= 0) return 0;
    int sx = ex - len + 1;
    int sy = ey - len + 1;
    if (ex >= N) {
        int diff = ex - (N - 1);
        ex -= diff;
        ey -= diff;
    }
    if (ey >= N) {
        int diff = ey - (N - 1);
        ex -= diff;
        ey -= diff;
    }
    if (sx < 0) {
        int diff = -sx;
        sx += diff;
        sy += diff;
    }
    if (sy < 0) {
        int diff = -sy;
        sx += diff;
        sy += diff;
    }
    if (ex < 0 || ey < 0) return 0;
    if (sx >= N || sy >= N) return 0;
    if (sx == 0 || sy == 0) return right_prefix[ey][ex];
    return right_prefix[ey][ex] - right_prefix[sy - 1][sx - 1];
}

void solution4() {
    long long answer = 0;
    for (int cy = -K; cy <= N + K; cy++) {
        long long S = 0, dS = 0;
        for (int cx = -K; cx <= N + K; cx++) {
            // update dS
            // +d1
            long long a = get_right_prefix_sum(cx + K, cy, K);
            // +d2
            long long b = get_left_prefix_sum(cx + 1, cy + K - 1, K - 1);
            // center idx
            long long c = -2 * get_prefix_sum(cx, cy - K + 1, cy + K - 1);
            // +d3
            long long d = get_left_prefix_sum(cx - K + 1, cy - 1, K - 1);
            // +d4
            long long e = get_right_prefix_sum(cx - 1, cy + K - 1, K);
            dS += a + b + c + d + e;
            S += dS;
            answer = max(answer, S);
        }
    }
    cout << answer << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        // init
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }
        // solution
        make_prefix_sum();
        cout << "Case #" << test_case << '\n';
        solution4();
    }
}