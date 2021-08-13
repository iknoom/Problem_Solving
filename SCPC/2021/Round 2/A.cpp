#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

void solution() {
    long long N;
    cin >> N;
    long long answer = 0;
    for (long long y = -N + 1; y <= N - 1; y++) {
        long long lx = 0, rx = 1000000;
        while (lx + 1 < rx) {
           long long mid = (lx + rx) / 2;
           if (y * y + mid * mid < N * N) {
               lx = mid;
           } else {
               rx = mid;
           }
        }
        answer += lx * 2 + 1;
    }
    cout << answer << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << '\n';
        solution();
    }
}