#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

long long pow_mod(long long n, long long r) {
    long long ret = 1;
    for (; r; r >>= 1) {
        if (r & 1) ret = ret * n % MOD;
        n = n * n % MOD;
    }
    return ret;
}

int main() {
    fastio;
    int M;
    cin >> M;
    long long answer = 0;
    while (M--) {
        long long a, b, inv_b;
        cin >> b >> a;
        // a * b^-1
        inv_b = pow_mod(b, MOD - 2);
        answer += a * inv_b % MOD;
        answer %= MOD;
    }
    cout << answer << '\n';
}