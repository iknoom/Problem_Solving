#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int cur = 0;
    for (int i = 0; i < K; i++) cur += v[i];
    int ans = cur;
    for (int i = K; i < N; i++) {
        cur -= v[i - K];
        cur += v[i];
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}