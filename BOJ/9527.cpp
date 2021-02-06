#include <bits/stdc++.h>

using namespace std;

long long sol(long long n) {
    if (n <= 1) return n;
    long long t = 1, ret = 0;
    int l = 0;
    while (t * 2 <= n) {
        t *= 2;
        l++;
    }
    ret += l * (t / 2);
    ret += n - t + 1;
    ret += sol(n - t);
    return ret;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    long long A, B;
    cin >> A >> B;
    cout << sol(B) - sol(A - 1) << '\n';
}