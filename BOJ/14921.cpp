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

    int answer = INF;
    for (int i = 0, j = N - 1; i < j; i++) {
        while (i < j && v[i] + v[j] >= 0) {
            if (abs(answer) > abs(v[i] + v[j])) {
                answer = v[i] + v[j];
            }
            j--;
        }
        if (i >= j) break;
        if (abs(answer) > abs(v[i] + v[j])) {
            answer = v[i] + v[j];
        }
    }
    cout << answer << '\n';
}