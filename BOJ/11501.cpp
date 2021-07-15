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
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        vector<pi> st;
        long long answer = 0;
        for (auto k : v) {
            answer -= k;
            int cnt = 1;
            while (!st.empty() && st.back().x <= k) {
                cnt += st.back().y;
                st.pop_back();
            }
            st.emplace_back(k, cnt);
        }
        for (auto k : st) {
            answer += (long long)k.x * k.y;
        }
        cout << answer << '\n';
    }
}