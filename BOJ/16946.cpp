#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, M, board[1000][1000], color[1000][1000];
vector<int> area;

bool is_ok(int x, int y) {
    return (0 <= x && x < M && 0 <= y && y < N);
}

int bfs(int x, int y, int cur_color) {
    queue<pi> q;
    q.push({x, y});
    color[y][x] = cur_color;
    int ret = 0;
    while (!q.empty()) {
        int x0 = q.front().first, y0 = q.front().second;
        q.pop();
        ret++;
        for (int i = 0; i < 4; i++) {
            int x1 = x0 + dx[i], y1 = y0 + dy[i];
            if (!is_ok(x1, y1)) continue;
            if (board[y1][x1] == 1) continue;
            if (color[y1][x1] < 0) {
                color[y1][x1] = cur_color;
                q.push({x1, y1});
            }
        }
    }
    return ret;
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
            color[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0 && color[i][j] == -1) {
                int A = bfs(j, i, (int)area.size());
                area.push_back(A);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            set<int> idx;
            for (int k = 0; k < 4; k++) {
                int x1 = j + dx[k], y1 = i + dy[k];
                if (!is_ok(x1, y1)) {
                    continue;
                }
                if (board[y1][x1] != 0) {
                    continue;
                }
                idx.insert(color[y1][x1]);
            }
            int sum_area = 0;
            for (auto k : idx) {
                sum_area += area[k];
            }
            board[i][j] += sum_area;
            board[i][j] %= 10;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}