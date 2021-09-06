#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> P(N), S(N), arr(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) arr[i] = i;
    int cnt = 0;
    while (cnt < 500000) {
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (P[arr[i]] != (i % 3)) {
                flag = false;
            }
        }
        if (flag) {
            cout << cnt << '\n';
            return 0;
        }
        vector<int> nxt_arr(N);
        for (int i = 0; i < N; i++) {
            nxt_arr[S[i]] = arr[i];
        }
        arr = nxt_arr;
        cnt++;
    }
    cout << -1 << '\n';
}