#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int cur = 1000000, ans = 0;
    while (cur) {
        if (cur * 7 <= N) {
            N -= cur * 7;
            ans += cur * 7;
        } else if (cur * 4 <= N) {
            N -= cur * 4;
            ans += cur * 4;
        }
        cur /= 10;
    }
    cur = 1;
    while (cur < ans) {
        if ((ans / cur) % 10 == 0) {
            ans += cur * 7;
            if ((ans / (cur * 10)) % 10 == 7) {
                ans -= cur * 70;
                ans += cur * 40;
            } else {
                ans -= cur * 40;
            }
        }
        cur *= 10;
    }
    cout << ans << '\n';
}