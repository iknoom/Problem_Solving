#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
using pi = pair<ll, ll>;
vector<pi> v;
int n;

bool check(ll min_L) {
    ll s = v[0].first;
    for (int i = 1; i < n; i++) {
        s = max(s + min_L, v[i].first);
        if (v[i].first + v[i].second < s)
            return false;
    }
    return true;
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        pi tmp;
        cin >> tmp.first >> tmp.second;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    ll L = 0, R = 1e18;
    while (L+1 < R) {
        ll mid = (L + R) / 2;
        if (check(mid))
            L = mid;
        else
            R = mid;
    }
    cout << L << endl;
}