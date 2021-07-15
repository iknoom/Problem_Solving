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
    int W, H;
    cin >> W >> H;
    int Q;
    cin >> Q;
    vector<pi> v(Q);
    for (int i = 0; i < Q; i++) {
        cin >> v[i].x >> v[i].y;
    }

    int dir, dist;
    cin >> dir >> dist;

    int answer = 0;
    for (auto[dir1, dist1] : v) {
        if (dir1 == dir) {
            answer += abs(dist - dist1);
        } else if ((dir1 == 1 && dir == 2) || (dir1 == 2 && dir == 1)) {
            answer += H + min(dist + dist1, (W - dist) + (W - dist1));
        } else if ((dir1 == 3 && dir == 4) || (dir1 == 4 && dir == 3)) {
            answer += W + min(dist + dist1, (H - dist) + (H - dist1));
        } else if (dir == 1) {
            if (dir1 == 3) answer += dist + dist1;
            if (dir1 == 4) answer += (W - dist) + dist1;
        } else if (dir == 2) {
            if (dir1 == 3) answer += dist + (H - dist1);
            if (dir1 == 4) answer += (W - dist) + (H - dist1);
        } else if (dir == 3) {
            if (dir1 == 1) answer += dist + dist1;
            if (dir1 == 2) answer += (H - dist) + dist1;
        } else if (dir == 4) {
            if (dir1 == 1) answer += dist + (W - dist1);
            if (dir1 == 2) answer += (H - dist) + (W - dist1);
        }
    }
    cout << answer << '\n';
}