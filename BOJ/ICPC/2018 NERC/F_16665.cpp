#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> primes;
    int tmp = n;
    for (int k = 2; k * k <= n; k++) {
        if (tmp == 1) break;
        if (tmp % k == 0) {
            primes.push_back(k);
            while (tmp % k == 0) tmp /= k;
        }
    }

    if (tmp > 1) {
        primes.push_back(tmp);
    }

    if (primes.size() < 2) {
        cout << "NO" << '\n';
        return 0;
    }

    int p = primes[0], q = primes[1], m = n - 1;
    for (int i = 1; i < min(p, m / q + 5); i++) {
        if ((m - q * i) % p == 0) {
            int j = (m - q * i) / p;
            cout << "YES" << '\n';
            cout << 2 << '\n';
            cout << i << ' ' << n/q << '\n';
            cout << j << ' ' << n/p << '\n';
        }
    }

}