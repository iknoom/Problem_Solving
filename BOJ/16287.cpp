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

int main() {
    fastio;
    int w, n;
    cin >> w >> n;
    vector<int> v(n), cnt(w + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int find_w = w - v[i] - v[j];
            if (0 <= find_w && find_w <= w && cnt[find_w]) {
                flag = true;
            }
        }
        for (int j = 0; j < i; j++) {
            if (v[i] + v[j] <= w) {
                cnt[v[i] + v[j]] = 1;
            }
        }
    }
    if (flag) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}