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

void solution() {
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(n);
    int cur = n;
    while (cur > 2) {
        cur = sqrt(cur) + 1;
        v.push_back(cur);
    }
    vector<pi> ans;
    int L = v.size();
    for (int i = 0; i < L - 1; i++) {
        int a = v[i + 1];
        int b = v[i];
        // cout << a << ' ' << b << '\n';
        for (int j = a + 1; j < b; j++) {
            ans.emplace_back(j, b);
        }
        ans.emplace_back(b, a);
        ans.emplace_back(b, a);
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.x << ' ' << p.y << '\n';
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}