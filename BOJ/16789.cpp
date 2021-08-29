#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<long long> A(N + 1), dp(N + 1);
    vector<vector<int>> idx(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        idx[l].push_back(l);
        idx[r].push_back(-l);
    }

    priority_queue<int, vector<int>, greater<>> pq, pq_del;
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        if (pq.empty()) {
            dp[i] = max(dp[i], dp[i - 1] + A[i]);
        } else {
            dp[i] = max(dp[i], dp[pq.top() - 1] + A[i]);
        }
        for (auto l : idx[i]) {
            if (l > 0) pq.push(l);
            else {
                pq_del.push(-l);
                while (!pq_del.empty() && pq.top() == pq_del.top()) {
                    pq.pop(); pq_del.pop();
                }
            }
        }
    }
    cout << dp[N] << '\n';
}