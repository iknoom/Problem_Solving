#include <bits/stdc++.h>

using namespace std;

long long pow(long long n, long long r, int MOD) {
    long long ret = 1;
    for (; r; r >>= 1) {
        if (r & 1) ret = ret * n % MOD;
        n = n * n % MOD;
    }
    return ret;
}
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int M, MOD;
    cin >> M;
    MOD = 1e9 + 7;
    int fact[4000001];
    fact[0] = 1;
    for (int i = 1; i <= 4000000; i++) {
        fact[i] = (long long)i * fact[i - 1] % MOD;
    }
    //  A * B^(p−2)  (mod p)
    for (int a, b; M--; ) {
        cin >> a >> b;
        long long ans = fact[a];
        ans = ans * pow(fact[b], MOD - 2, MOD) % MOD;
        ans = ans * pow(fact[a - b], MOD - 2, MOD) % MOD;
        cout << ans << endl;
    }
}