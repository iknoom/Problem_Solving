#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<long long, long long>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // squad
    int N, C;
    cin >> N >> C;
    vector<pi> v(N);
    vector<long long> dp(C + 1);
    for (int i = 0; i < N; i++) {
        long long c, d, h;
        cin >> c >> d >> h;
        v[i] = {c, -d * h};
    }
    // fill dp
    sort(all(v));
    for (auto [c, dh] : v) {
        dh = -dh;
        if (dp[c] >= dh) continue;
        for (int i = 1; i * c <= C; i++) {
            dp[i * c] = max(dp[i * c], dh * i);
        }
    }
    // get max values
    vector<pi> values;
    for (int c = 0; c <= C; c++) {
        if (!dp[c]) continue;
        if (!values.empty() && values.back().x >= dp[c]) {
            continue;
        }
        values.emplace_back(dp[c], c);
    }
    // monster
    int M;
    cin >> M;
    while (M--) {
        long long D, H, DH;
        cin >> D >> H;
        DH = D * H;
        if (values.back().x < DH + 1) {
            cout << -1 << '\n';
        } else {
            pi &p = *upper_bound(all(values), pi(DH + 1, 0L));
            cout << p.y << ' ';
        }
    }
}