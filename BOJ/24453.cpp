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
    int N, M, X, Y;
    cin >> N >> M;
    vector<int> errors(M);
    errors.push_back(0);
    for (int i = 0; i < M; i++) {
        cin >> errors[i];
    }
    errors.push_back(N + 1);
    cin >> X >> Y;
    sort(all(errors));

    int l = 0, answer = INF;
    // 간격이 X보다 큰 최소 인덱스 차이
    for (int r = 0; r < M + 2; r++) {
        if (errors[r] - errors[l] - 1 >= X) {
            answer = min(answer, r - l - 1);
        }
        while (l + 1 <= r && errors[r] - errors[l + 1] - 1 >= X) {
            l++;
        }
        if (errors[r] - errors[l] - 1 >= X) {
            answer = min(answer, r - l - 1);
        }
    }
    cout << M - max(answer, Y) << '\n';
}