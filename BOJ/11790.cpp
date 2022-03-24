#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e14;

int N;
vector<long long> powPrimes[48];
vector<long long> prefixMul[48];

void fillPrimes() {
    bool isPrime[10000000];
    fill_n(isPrime, 10000000, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 10000000; i++) {
        if (!isPrime[i]) continue;
        powPrimes[1].push_back(i);
        for (int j = 2; i * j < 10000000; j++) {
            isPrime[i * j] = false;
        }
    }
    N = (int)powPrimes[1].size();
    for (int i = 2; i < 48; i++) {
        for (int j = 0; j < (int)powPrimes[i - 1].size(); j++) {
            if ((double)powPrimes[i - 1][j] * (double)powPrimes[1][j] > (double)INF) {
                break;
            }
            powPrimes[i].push_back(powPrimes[i - 1][j] * powPrimes[1][j]);
        }
    }
}

void fillPrefix() {
    for (int i = 0; i < N; i++) {
        prefixMul[0].push_back(1);
    }
    for (int i = 1; i < 48; i++) {
        long long S = 1;
        for (long long powPrime : powPrimes[i]) {
            S *= powPrime % MOD;
            S %= MOD;
            prefixMul[i].push_back(S);
        }
    }
}

long long myPow(long long n, long long r) {
    long long ret = 1;
    for (; r; r >>= 1) {
        if (r & 1) ret = ret * n % MOD;
        n = n * n % MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fillPrimes();
    fillPrefix();
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        long long X;
        cin >> X;
        long long ret = 1;
        for (int i = 2; i < 48; i++) {
            int j = upper_bound(powPrimes[i].begin(), powPrimes[i].end(), X) - powPrimes[i].begin();
            if (j == 0) {
                break;
            }
            ret = ret * myPow(prefixMul[i - 2][j - 1], MOD - 2) % MOD;
            ret = ret * prefixMul[i - 1][j - 1] % MOD;
        }
        cout << "Case " << testcase << ": " << ret << '\n';
    }
}