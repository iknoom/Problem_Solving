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
    int M;
    cin >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(all(v));
    int l = 0, r = N - 1, answer = 0;
    while (l < r) {
        if (v[l] + v[r] == M) {
            answer++;
            l++; r--;
        } else if (v[l] + v[r] > M) {
            r--;
        } else if (v[l] + v[r] < M) {
            l++;
        }
    }
    cout << answer << '\n';
}