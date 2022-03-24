#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N;
    cin >> N;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    long long before = 0, answer = 1;
    for (int i = 1; i < N; i++) {
        if (v[before] > v[i]) {
            continue;
        }
        answer *= (i - before + 1);
        answer %= MOD;
        before = i;
    }
    cout << answer << '\n';
}