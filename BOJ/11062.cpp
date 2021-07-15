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
int N, dp[1000][1000], cards[1000];

int get_max(int l, int r, int S) {
    if (dp[l][r] != INF) {
        return dp[l][r];
    }
    if (l == r) {
        dp[l][r] = cards[r];
        return dp[l][r];
    }
    int left = cards[l] + (S - cards[l] - get_max(l + 1, r, S - cards[l]));
    int right = cards[r] + (S - cards[r] - get_max(l, r - 1, S - cards[r]));
    dp[l][r] = max(left, right);
    return dp[l][r];
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        int S = 0;
        for (int i = 0; i < N; i++) {
            cin >> cards[i];
            S += cards[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = INF;
            }
        }
        cout << get_max(0, N - 1, S) << '\n';
    }
}