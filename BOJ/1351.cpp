#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
map<long long, long long> dp;
long long N, P, Q;

long long solution(long long n) {
    if (dp.find(n) != dp.end()) {
        return dp[n];
    }
    long long ret = solution(n / P) + solution(n / Q);
    dp[n] = ret;
    return ret;
}

int main() {
    fastio;
    cin >> N >> P >> Q;
    dp[0] = 1;
    cout << solution(N) << '\n';
}