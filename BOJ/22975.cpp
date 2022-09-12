#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct line {
    int dx, dy, l, r;
};

bool cmp(line &a, line &b) {
    if ((long long)a.dy * b.dx == (long long)b.dy * a.dx) {
        return a.r < b.r;
    } else {
        return (long long)a.dy * b.dx < (long long)b.dy * a.dx;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    vector<line> lines;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            lines.push_back({j - i, H[j] - H[i], i, j});
        }
    }
    sort(all(lines), cmp);

    vector<int> dp(N, 1);
    for (auto l : lines) {
        // cout << l.dy << ' ' << l.dx << ' ' << l.l << ' ' << l.r << '\n';
        dp[l.r] = max(dp[l.r], dp[l.l] + 1);
    }
    cout << N - *max_element(all(dp)) << '\n';
}