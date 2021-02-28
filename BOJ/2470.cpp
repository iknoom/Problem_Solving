#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int INF = 1e9 + 2;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int N;
    cin >> N;
    set<int> S;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        S.insert(k);
        v.push_back(k);
    }

    int a = INF, b = INF;
    for (auto x : v) {
        int y;
        S.erase(x);
        if (S.lower_bound(-x) != S.begin()) {
            y = *(--S.lower_bound(-x));
            if (abs(a + b) > abs(x + y)) {
                a = x;
                b = y;
            }
        }
        if (S.lower_bound(-x) != S.end()) {
            y = *S.lower_bound(-x);
            if (abs(a + b) > abs(x + y)) {
                a = x;
                b = y;
            }
        }
        S.insert(x);
    }
    cout << min(a, b) << ' ' << max(a, b) << '\n';
}