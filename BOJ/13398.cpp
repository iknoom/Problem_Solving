#include <bits/stdc++.h>

using namespace std;
int N, ans, S1, S2, t, A[100001], dp[100001];
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    t = -1e9;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        t = max(t, A[i]);
    }

    for (int i = 0; i < N; i++) {
        S2 = max(S2 + A[i], 0);
        S2 = max(S2, S1);
        S1 = max(S1 + A[i], 0);
        ans = max(ans, max(S1, S2));
    }

    if (t < 0) {
        cout << t << endl;
    }
    else {
        cout << ans << endl;
    }
}