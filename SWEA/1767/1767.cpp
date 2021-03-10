#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int MAX = 12;
int N, M, board[MAX][MAX], answer_core, answer_line, cur_line, cur_core;
vector<pi> core;

int connect(int x, int y, int i, int inc) {
    int ret = 0;
    x += dx[i];
    y += dy[i];
    while (0 <= x && x < N && 0 <= y && y < N) {
        if (board[y][x] == inc) {
            board[y][x] = 0;
            x += dx[i];
            y += dy[i];
            continue;
        } else if (board[y][x] > 0) {
            return -1;
        } else {
            ret += 1;
            board[y][x] += inc;
            x += dx[i];
            y += dy[i];
        }
    }
    return ret;
}

void dfs(int u) {
    if (u == M) {
        if (cur_core > answer_core) {
            answer_core = cur_core;
            answer_line = cur_line;
        } else if (cur_core == answer_core) {
            answer_line = min(answer_line, cur_line);
        }
        return;
    }
    int x = core[u].first;
    int y = core[u].second;
    for (int i = 0; i < 4; i++) {
        int length;
        length = connect(x, y, i, N + u);
        if (length > 0) {
            cur_line += length;
            cur_core += 1;
            dfs(u + 1);
            cur_core -= 1;
            cur_line -= length;
        }
        connect(x, y, i, N + u);
    }
    dfs(u + 1);
}

void solution(int test) {
    core.clear();
    cur_line = 0;
    cur_core = 0;
    answer_core = 0;
    answer_line = 0;
    // input
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            cin >> board[j][i];
            if (board[j][i]) {
                if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                    cur_core++;
                } else {
                    core.emplace_back(i, j);
                }
            }
        }
    // solution
    answer_core = cur_core;
    M = core.size();
    dfs(0);
    cout << "#" << test << ' ' << answer_line << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solution(i);
    }
    return 0;
}