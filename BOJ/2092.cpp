#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e6;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int T, A, S, B;
    cin >> T >> A >> S >> B;
    vector<int> counter(T + 1); // counter[i] : i의 개수
    for (int i = 0; i < A; i++) {
        int e;
        cin >> e;
        counter[e]++;
    }



    /* 3이 두개
    K=0 : {}
    K=1 : {1}, {2} | {3}
    K=2 : {1, 1}, {1, 2}, {2, 2} | {3, 3}, {1, 3}, {2, 3}
    K=3 : {1, 1, 2}, {1, 2, 2} | {1, 3, 3} {2, 3, 3} {1, 1, 3} {1, 2, 3} {2, 2, 3}
    K=4 : {1, 1, 2, 2} | {1, 1, 3, 3} {1, 2, 3, 3}, {2, 2, 3, 3} {1, 1, 2, 3}, {1, 2, 2, 3}
    K=5 :
    */


    vector<int> dp(A + 1); // [i번 째 수까지 썼을 때][집합의 크기가 j] 개수
    dp[0] = 1;
    for (int i = 0; i <= T; i++) {
        vector<int> next_dp(A + 1);
        // 1. dp -> next_dp
        for (int j = 0; j <= A; j++) {
            next_dp[j] = dp[j];
        }
        // 2. 집합 개수 갱신
        for (int j = 0; j <= A; j++) {
            for (int k = 1; k <= counter[i]; k++) {
                if (j - k >= 0) {
                    next_dp[j] += dp[j - k];
                    next_dp[j] %= MOD;
                }
            }
        }
        // 3. next_dp -> dp
        for (int j = 0; j <= A; j++) {
            dp[j] = next_dp[j];
        }
    }
    int answer = 0;
    for (int i = S; i <= B; i++) {
        answer += dp[i];
        answer %= MOD;
    }
    cout << answer << '\n';
}