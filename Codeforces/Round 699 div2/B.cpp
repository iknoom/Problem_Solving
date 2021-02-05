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
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    // solution
    int last = -1;
    while (k) {
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (h[i] < h[i + 1]) {
                last = i;
                h[i]++;
                flag = true;
                k--;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    if (k) {
        cout << -1 << '\n';
    } else {
        cout << last + 1 << '\n';
    }
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}