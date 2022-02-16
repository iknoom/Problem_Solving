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
    vector<int> v(N);
    long long answer = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        answer += v[i];
    }
    answer -= *min_element(all(v));
    answer -= *max_element(all(v));
    cout << answer << '\n';
}