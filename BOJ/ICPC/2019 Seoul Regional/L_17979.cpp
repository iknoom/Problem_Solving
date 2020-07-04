#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
using pi = pair<ll, ll>;

vector<pair<pi, ll>> v;
int n, m;
int val[101];
ll dp[15003];

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++) {
        pi tmp; ll tmp2;
        cin >> tmp.second >> tmp.first >> tmp2;
        v.push_back({ tmp, (tmp.first - tmp.second) * val[tmp2] });
    }
    sort(v.begin(), v.end());
    int cur = 0;
    dp[0] = 0;
    for (int i = 1; i <= 15000; i++) {
        dp[i] = dp[i-1];
        while (cur < n && v[cur].first.first == i){

            // cout << v[cur].first.second << " " << v[cur].first.first;
            // cout << " " << v[cur].second;
            dp[i] = max(dp[i], dp[v[cur].first.second] + v[cur].second);
            cur++;
            // cout << " " << dp[i] << endl;
        }
    }
    cout << dp[15000] << endl;
}