#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int solve(int n) {
    int ret = 0;
    int cur = n;
    while (cur) {
        while (cur % 10 != 1) {
            cur += n;
        }
        cur /= 10;
        ret += 1;
    }
    return ret;
}

int main() {
    fastio;
    int n;
    while (cin >> n) {
        int answer = solve(n);
        cout << answer << '\n';
    }
}