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

long long get_left_prefix_sum_b(int ex, int ey, int len) {
    long long ret = 0;
    for (int k = 0; k < len; k++) {
        int nx = ex + k, ny = ey - k;
        if (nx < 0 || nx >= N) continue;
        if (ny < 0 || ny >= N) continue;
        ret += arr[ny][nx];
    }
    return ret;
}

long long get_right_prefix_sum_b(int ex, int ey, int len) {
    long long ret = 0;
    for (int k = 0; k < len; k++) {
        int nx = ex - k, ny = ey - k;
        if (nx < 0 || nx >= N) continue;
        if (ny < 0 || ny >= N) continue;
        ret += arr[ny][nx];
    }
    return ret;
}

void solution3() {
    long long answer = 0;
    for (int cy = -K; cy <= N + K; cy++) {
        long long S = 0, dS = 0;
        for (int cx = -K; cx <= N + K; cx++) {
            // update dS
            // +d1
            long long a = get_right_prefix_sum_b(cx + K, cy, K);
            // +d2
            long long b = get_left_prefix_sum_b(cx + 1, cy + K - 1, K - 1);
            // center idx
            long long c = -2 * get_prefix_sum(cx, cy - K + 1, cy + K - 1);
            // +d3
            long long d = get_left_prefix_sum_b(cx - K + 1, cy - 1, K - 1);
            // +d4
            long long e = get_right_prefix_sum_b(cx - 1, cy + K - 1, K);
            dS += a + b + c + d + e;
            S += dS;
            answer = max(answer, S);
        }
    }
    cout << answer << '\n';
}

void solution4() {
    long long answer = 0;
    for (int cy = -K; cy <= N + K; cy++) {
        long long S = 0, dS = 0;
        for (int cx = -K; cx <= N + K; cx++) {
            // update dS
            // +d1
            long long a = get_right_prefix_sum(cx + K, cy, K);
            long long a1 = get_right_prefix_sum_b(cx + K, cy, K);
            if (a != a1) {
                cout << "right: " << cx + K << ' ' << cy << ' ' << K << '\n';
                cout << "a, a2: " << a << ' ' << a1 << '\n';
            }
            // +d2
            long long b = get_left_prefix_sum(cx + 1, cy + K - 1, K - 1);
            long long b1 = get_left_prefix_sum_b(cx + 1, cy + K - 1, K - 1);
            if (b != b1) {
                cout << "left: " << cx + 1 << ' ' << cy + K - 1 << ' ' << K - 1 << '\n';
                cout << "b, b2: " << b << ' ' << b1 << '\n';
            }
            // center idx
            long long c = -2 * get_prefix_sum(cx, cy - K + 1, cy + K - 1);
            // +d3
            long long d = get_left_prefix_sum(cx - K + 1, cy - 1, K - 1);
            long long d1 = get_left_prefix_sum_b(cx - K + 1, cy - 1, K - 1);
            if (d != d1) {
                cout << "left: " << cx - K + 1 << ' ' << cy - 1 << ' ' << K - 1 << '\n';
                cout << "d, d2: " << d << ' ' << d1 << '\n';
            }
            // +d4
            long long e = get_right_prefix_sum(cx - 1, cy + K - 1, K);
            long long e1 = get_right_prefix_sum_b(cx - 1, cy + K - 1, K);
            if (e != e1) {
                cout << "right: " << cx - 1 << ' ' << cy + K - 1 << ' ' << K << '\n';
                cout << "e, e2: " << e << ' ' << e1 << '\n';
            }
            dS += a + b + c + d + e;
            S += dS;
            answer = max(answer, S);
        }
    }
    cout << answer << '\n';
}

void solution1() {
    long long answer = 0;
    for (int i = -K; i <= N + K; i++) {
        for (int j = -K; j <= N + K; j++) {
            long long cur = 0;
            for (int h = i - K + 1; h <= i + K - 1; h++) {
                if (h < 0 || h >= N) continue;
                int diff = K - abs(i - h);
                for (int w = j - diff + 1; w <= j + diff - 1; w++) {
                    if (w < 0 || w >= N) continue;
                    cur += arr[h][w] * (K - abs(i - h) - abs(j - w));
                }
            }
            answer = max(answer, cur);
        }
    }
    cout << answer << '\n';
}

void solution2() {
    long long answer = 0;
    long long S = 0;
    for (int cy = -K; cy <= N + K; cy++) {
        for (int cx = -K; cx <= N + K; cx++) {
            answer = max(answer, S);
            // update S
            for (int k = 0; k < K; k++) {
                if (cx - k < 0 || cx - k >= N) continue;
                S -= get_prefix_sum(cx - k, cy - (K - k - 1), cy + (K - k - 1));
            }
            for (int k = 1; k <= K; k++) {
                if (cx + k < 0 || cx + k >= N) continue;
                S += get_prefix_sum(cx + k, cy - (K - k), cy + (K - k));
            }
        }
    }
    cout << answer << '\n';
}

int main() {
    freopen("C:\\Problem_Solving\\SCPC\\2021\\Round 2\\sample7.txt", "r", stdin);
//    fastio;
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
        solution1();
        solution2();
        solution3();
        solution4();
    }
}