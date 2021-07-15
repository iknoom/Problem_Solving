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
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(all(v));
    int cur = v[1] - v[0];
    for (int i = 1; i < N - 1; i++) {
        int diff = v[i + 1] - v[i];
        cur = gcd(cur, diff);
    }
    int answer = 0;
    for (int i = 0; i < N - 1; i++) {
        answer += (v[i + 1] - v[i]) / cur - 1;
    }
    cout << answer << '\n';
}