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
    int answer = 0, N;
    cin >> N;
    vector<int> v;
    unordered_map<int, int> S;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        v.push_back(k);
        S[k] += 1;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            // a + b = c
            // a + 0 = a
            // 0 + b = b
            // 0 + 0 = 0
            if (v[i] == 0 && v[j] == 0) {
                if (S[0] > 2) {
                    answer += S[0];
                    S.erase(0);
                }
            } else if (v[i] == 0) {
                if (S[v[j]] > 1) {
                    answer += S[v[j]];
                    S.erase(v[j]);
                }
            } else if (v[j] == 0) {
                if (S[v[i]] > 1) {
                    answer += S[v[i]];
                    S.erase(v[i]);
                }
            } else {
                answer += S[v[i] + v[j]];
                S.erase(v[i] + v[j]);
            }
        }
    }
    cout << answer << '\n';
}