#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int N, S;
    cin >> N >> S;
    vector<pi> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y;
    }
    sort(all(v));
    vector<int> dp(N + 1), height;
    height.push_back(-INF);
    for (int i = 1; i <= N; i++) {
        int height_i = v[i - 1].x, value = v[i - 1].y;
        height.push_back(height_i);
        int j = upper_bound(all(height), height_i - S) - height.begin();
        dp[i] = max(dp[i - 1], dp[j - 1] + value);
//        cout << height_i << ' ' << value << ' ' << dp[i] <<'\n';
    }
    cout << dp[N] << '\n';
}