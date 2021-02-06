#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, MOD = 16769023, ret = 1;
    cin >> n;
    n = (n + 1) / 2;
    while (n--) {
        ret *= 2;
        ret %= MOD;
    }
    cout << ret << endl;
}