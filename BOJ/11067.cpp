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

void solution() {
    int n;
    cin >> n;
    vector<pi> cafe(n), answer(n);
    for (int i = 0; i < n; i++) {
        cin >> cafe[i].x >> cafe[i].y;
    }
    sort(all(cafe));
    int before_y = 0, cnt = 0;
    for (int i = 0; i < n;) {
        int j = i, cur_x = cafe[i].x;
        vector<int> y_axis;
        while (j < n && cafe[j].x == cur_x) {
            y_axis.push_back(cafe[j].y);
            j++;
        }
        int m = sz(y_axis);
        if (before_y == y_axis.back()) {
            for (int k = m - 1; k >= 0; k--) {
                answer[cnt++] = {cur_x, y_axis[k]};
            }
            before_y = y_axis[0];
        } else {
            for (int k = 0; k < m; k++) {
                answer[cnt++] = {cur_x, y_axis[k]};
            }
            before_y = y_axis.back();
        }
        i = j;
    }
    int m;
    cin >> m;
    while (m--) {
        int i;
        cin >> i;
        i--;
        cout << answer[i].x << ' ' << answer[i].y << '\n';
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