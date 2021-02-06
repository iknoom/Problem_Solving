#include <bits/stdc++.h>

using namespace std;
int cnt[7][2];
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    while (N--) {
        int a, b;
        cin >> a >> b;
        cnt[b][a]++;
    }
    int ans = 0;
    for (int i = 1; i < 7; i++){
        ans += cnt[i][0] / K;
        if (cnt[i][0] % K) ans++;
        ans += cnt[i][1] / K;
        if (cnt[i][1] % K) ans++;
    }
    cout << ans << '\n';
}