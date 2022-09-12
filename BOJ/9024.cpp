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

void solution() {
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(all(v));
    int minValue = INF, cnt = 0;
    for (int i = 0; i < N; i++) {
        int diff = K - v[i];
        int a = lower_bound(v.begin() + i + 1, v.end(), diff) - v.begin();
        vector<int> tmp;
        if (a < N) {
            tmp.push_back(a);
        }
        if (a - 1 >= 0) {
            tmp.push_back(a - 1);
        }
        for (auto k : tmp) {
            if (k <= i) continue;
            // cout << v[i] << ' ' << v[k] << '\n';
            if (abs(K - v[i] - v[k]) == minValue) {
                cnt++;
            }
            if (abs(K - v[i] - v[k]) < minValue) {
                minValue = abs(K - v[i] - v[k]);
                cnt = 1;
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        solution();
    }
}