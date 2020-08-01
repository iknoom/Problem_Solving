#include <bits/stdc++.h>

using namespace std;
const int MAX = 200005;
typedef long long ll;
ll N, M, K;
vector<ll> s_idx_dp[26];
vector<ll> e_idx_dp[26];
vector<ll> sum_dp[26];
string block[MAX];
string en_map;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (ll i = 0; i < K; i++) cin >> block[i];
    cin >> en_map;

    for (ll i = 0; i < K; i++){
        sum_dp[i].push_back(0LL);
        ll cur = 0;
        for (ll j = 0; j < M; j++){
            if(block[i][j] == 'R'){
                continue;
            }
            else{
                sum_dp[i].push_back(sum_dp[i].back() + (j - cur + 1));
                s_idx_dp[i].push_back(cur);
                e_idx_dp[i].push_back(j);
                cur = j + 1LL;
            }
        }
    }

    ll L = M - 1, R = M - 1;
    ll ans = 0LL;

    ll l = M - 1 , r = M - 1;
    int i = en_map[N - 1] - 'A';

    while (true){
        if (block[i][l - 1] == 'U') break;
        if (l == 0) break;
        l--;
    }

    L = l;
    R = r;
    ans += r - l + 1LL;

    for(ll row = N - 2; row >= 0; row--){
        ll l, r;
        ll i = en_map[row] - 'A';

        if ((int)e_idx_dp[i].size() == 1){
            if (e_idx_dp[i][0] < L) break;
            if (e_idx_dp[i][0] > R) break;
            l = 0LL;
            r = 0LL;
        }
        else {
            auto l_bound = lower_bound(e_idx_dp[i].begin(), e_idx_dp[i].end(), L);
            auto r_bound = upper_bound(e_idx_dp[i].begin(), e_idx_dp[i].end(), R);
            if (l_bound == e_idx_dp[i].end()) break;
            if (r_bound == e_idx_dp[i].begin()) break;

            l = l_bound - e_idx_dp[i].begin();
            r = (--r_bound) - e_idx_dp[i].begin();
        }
        //cout << sum_dp[i][r + 1] << ' ' << sum_dp[i][l] << endl;
        ans += (long long)sum_dp[i][r + 1] - (long long)sum_dp[i][l];
        L = s_idx_dp[i][l];
        R = e_idx_dp[i][r];
    }
    cout << ans << '\n';
}