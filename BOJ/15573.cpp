#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
int N, M, K, S[1001][1001], vst[1001][1001];


bool BFS(int D) {
    queue<pi> q;
    memset(vst, 0, sizeof(vst));
    for (int i = 0; i < M; i++) {
        vst[0][i] = 1;
        q.push({i, 0});
    }
    for (int i = 1; i < N; i++) {
        vst[i][0] = 1;
        q.push({0, i});
        if (M > 1) {
            vst[i][M - 1] = 1;
            q.push({M - 1, i});
        }
    }

    int ret = 0;
    while (!q.empty()) {
        int x0, y0;
        x0 = q.front().first; y0 = q.front().second;
        q.pop();
        if (S[y0][x0] > D) continue;
        else ret++;
        for (int i = 0; i < 4; i++) {
            int x1, y1;
            x1 = x0 + dx[i];
            y1 = y0 + dy[i];
            if (x1 < 0 || M <= x1 || y1 < 0 || N <= y1) continue;
            if (vst[y1][x1] == 1) continue;
            vst[y1][x1] = 1;
            q.push({x1, y1});
        }
    }
    return ret >= K;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> S[i][j];
    }

    int L, R;
    L = 0; R = 1000003;
    while (L + 1 < R) {
        int mid = (L + R) / 2;
        if (BFS(mid)) {
            R = mid;
        }
        else {
            L = mid;
        }
    }
    cout << R << '\n';
}