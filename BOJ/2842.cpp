#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

struct node{
    int x, y, d;
    bool operator<(const node & t) const{
        return d > t.d;
    }
};

int N, hight[50][50], is_K[50][50], sx, sy, cnt_K;

bool is_ok(int x, int y) {
    return (0 <= x && x < N && 0 <= y && y < N);
}

int solve(int lowest) {
    if (lowest > hight[sy][sx]) return -1;
    int highest = hight[sy][sx], cnt = 0;
    int vst[50][50] = {0,};
    priority_queue<node, vector<node>> PQ;
    PQ.push({sx, sy, hight[sy][sx]});
    vst[sy][sx] = 1;
    while (!PQ.empty()) {
        int cx, cy, cd;
        cx = PQ.top().x;
        cy = PQ.top().y;
        cd = PQ.top().d;
        PQ.pop();

        highest = max(highest, cd);
        cnt += is_K[cy][cx];
        if (cnt == cnt_K) return highest - lowest;

        for (int i = 0; i < 8; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (!is_ok(nx, ny)) continue;
            if (vst[ny][nx]) continue;
            if (hight[ny][nx] < lowest) continue;
            vst[ny][nx] = 1;
            PQ.push({nx, ny, hight[ny][nx]});
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < N; j++) {
            if (S[j] == 'K') {
                is_K[i][j] = 1;
                cnt_K++;
            }
            if (S[j] == 'P') {
                sx = j;
                sy = i;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> hight[i][j];
        }
    }
    int ans = 1e9;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int ret = solve(hight[i][j]);
            if (ret < 0) continue;
            ans = min(ans, ret);
        }
    }
    cout << ans << '\n';
}