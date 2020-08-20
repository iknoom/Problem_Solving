#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    long long a = 1, b = 1;
    while (--N) {
        long long t = a + b;
        a = b;
        b = t;
    }
    cout << 2 * (a + b) << endl;
}