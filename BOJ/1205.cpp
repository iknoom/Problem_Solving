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
    int N, score, P;
    cin >> N >> score >> P;
    int kth = 1, cnt = 0;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        if (k > score) {
            kth++;
        } else if (k == score) {
            cnt++;
        }
    }

    if (kth + cnt > P) {
        cout << -1 << '\n';
    } else {
        cout << kth << '\n';
    }

}