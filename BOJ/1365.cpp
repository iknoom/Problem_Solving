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

int main() {
    fastio;
    int N;
    cin >> N;
    vector<int> dp;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        if (dp.empty() || dp.back() < val) {
            dp.push_back(val);
        } else {
            auto it = lower_bound(all(dp), val);
            *it = val;
        }
    }
    cout << N - dp.size() << '\n';
}