#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const long long INF = 1e18;
const int SIZE = 100000;
const int MAX_H = 100000;
int start, H[SIZE];
long long A[SIZE], B[SIZE], a[4 * SIZE], b[4 * SIZE];

void query(int l, int r, long long av, long long bv) {
    l += start;
    r += start;
    while (l <= r) {
        if (r % 2 == 0) {
            a[r] += av;
            b[r] += bv;
            r--;
        }
        if (l % 2 == 1) {
            a[l] += av;
            b[l] += bv;
            l++;
        }
        l /= 2;
        r /= 2;
    }
}

long long f(int i) {
    int j = i + start;
    long long ret = a[j] * i + b[j];
    while (j) {
        j /= 2;
        ret += a[j] * i + b[j];
    }
    return ret;
}

void update(int i, long long sign) {
    query(0, H[i], -B[i] * sign, B[i] * H[i] * sign);
    query(H[i], MAX_H, A[i] * sign, -A[i] * H[i] * sign);
}

long long get_min_fi() {
    int lo = 0, hi = MAX_H;
    while (hi - lo >= 3) {
        int p = (lo * 2 + hi) / 3;
        int q = (lo + hi * 2) / 3;
        if (f(p) <= f(q)) {
            hi = q;
        } else {
            lo = p;
        }
    }
    long long ret = INF;
    for (int i = lo; i <= hi; i++) {
        ret = min(ret, f(i));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // input
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> H[i];
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    start = 1;
    while (start < MAX_H) start *= 2;

    // solution
    long long answer = INF;
    for (int i = 0; i < K; i++) {
        update(i, 1);
    }
    answer = min(answer, get_min_fi());

    for (int i = K; i < N; i++) {
        update(i, 1);
        update(i - K, -1);
        answer = min(answer, get_min_fi());
    }
    cout << answer << '\n';
}