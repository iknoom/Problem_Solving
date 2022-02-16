#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, char>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L, N, T;
    cin >> L >> N >> T;
    vector<pi> balls(N);
    for (int i = 0; i < N; i++) {
        cin >> balls[i].x >> balls[i].y;
    }
    int answer = 0;
    while (T--) {
        vector<int> vst(L + 1);
        for (auto& ball : balls) {
            if (ball.y == 'R') {
                ball.x++;
            } else {
                ball.x--;
            }
            if (ball.x == 0) {
                ball.y = 'R';
            }
            if (ball.x == L) {
                ball.y = 'L';
            }
            if (vst[ball.x] > 0) {
                answer++;
            }
            vst[ball.x]++;
        }
    }
    cout << answer << '\n';
}