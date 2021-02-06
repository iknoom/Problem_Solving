#include <bits/stdc++.h>
using namespace std;

vector<long long> make_fact(int n, int mod) {
    vector<long long> fact = {1, 1};
    for (int i = 2; i < n + 1; i++) {
        fact.push_back((fact.back() * i) % mod);
    }
    return fact;
}

vector<long long> make_factinv(int n, int mod){
    vector<long long> inv = {1, 1};
    vector<long long> factinv = {1, 1};
    for (int i = 2; i < n + 1; i++) {
        inv.push_back((inv[mod % i] * (mod - mod / i)) % mod);
        factinv.push_back((factinv.back() * inv.back()) % mod);
    }
    return factinv;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int M;
    cin >> M;
    int MOD = 1000000007;
    int MAX = 4000001;
    vector<long long> fact = make_fact(MAX, MOD);
    vector<long long> factinv = make_factinv(MAX, MOD);
    while (M--) {
        int n, k;
        cin >> n >> k;
        long long ret = fact[n];
        ret *= factinv[k]; ret %= MOD;
        ret *= factinv[n - k]; ret %= MOD;
        cout << ret << '\n';
    }
}