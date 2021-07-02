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
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    set<int> S;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S.insert(v[i] + v[j]);
        }
    }
    int answer = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v[i] >= v[j]) continue;
            int diff = v[j] - v[i];
            if (S.find(diff) != S.end()) {
                answer = max(answer, v[j]);
            }
        }
    }
    cout << answer << '\n';
}