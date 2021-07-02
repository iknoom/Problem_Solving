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

int main() {
    fastio;
    int N;
    cin >> N;
    vector<pi> lines(N);
    for (int i = 0; i < N; i++) {
        cin >> lines[i].x >> lines[i].y;
    }
    sort(all(lines));

    vector<int> dp;
    vector<pi> trace;
    for (auto[_, cur] : lines) {
        if (dp.empty() || dp.back() < cur) {
            trace.emplace_back(sz(dp), cur);
            dp.push_back(cur);
        } else {
            int idx = lower_bound(all(dp), cur) - dp.begin();
            trace.emplace_back(idx, cur);
            dp[idx] = cur;
        }
    }

    set<int> S;
    int p = sz(dp) - 1;
    reverse(all(trace));
    for (auto[u, v] : trace) {
        if (u == p) {
            p--;
            S.insert(v);
        }
    }

    vector<int> answer;
    for (auto[u, v] : lines) {
        if (S.find(v) == S.end()) {
            answer.push_back(u);
        }
    }
    sort(all(answer));
    cout << sz(answer) << '\n';
    for (auto k : answer) {
        cout << k << '\n';
    }
}