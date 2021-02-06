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
    vector<long long> w(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        ans += w[i];
    }
    vector<int> cnt(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        cnt[u]++;
        cnt[v]++;
    }
    vector<long long> vals;
    for (int i = 0; i < n; i++) {
        while (cnt[i] > 1) {
            vals.push_back(-w[i]);
            cnt[i]--;
        }
    }
    sort(all(vals));
    cout << ans << ' ';
    for (int i = 0; i < n - 2; i++) {
        ans -= vals[i];
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}