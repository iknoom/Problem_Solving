#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    long long ans = 0, c;
    cin >> c;
    for (int i = 0; i < N; i++) {
        ans += v[i] / c;
        if (v[i] % c) ans++;
    }
    cout << ans * c << '\n';
}