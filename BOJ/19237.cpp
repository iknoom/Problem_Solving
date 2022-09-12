#include <iostream>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct grid {
    int t, shark_i;
    bool is_shark_in;
} board[20][20];

struct shark {
    int d, d_priority[4][4];
} shark_array[400];

int N, M, k, nxt_board[20][20];

void move_shark(int i, int x, int y) {
    // 아무 냄새가 없는 방향으로 이동
    for (int j = 0; j < 4; j++) {
        int d = shark_array[i].d_priority[shark_array[i].d][j];
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || N <= nx) continue;
        if (ny < 0 || N <= ny) continue;
        if (board[ny][nx].t > 0) continue;
        // move
        shark_array[i].d = d;
        nxt_board[ny][nx] = nxt_board[ny][nx] < 0 ? i : min(nxt_board[ny][nx], i);
        return;
    }
    // 본인 냄새가 있는 방향으로 이동
    for (int j = 0; j < 4; j++) {
        int d = shark_array[i].d_priority[shark_array[i].d][j];
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || N <= nx) continue;
        if (ny < 0 || N <= ny) continue;
        if (board[ny][nx].shark_i != i) continue;
        // move
        shark_array[i].d = d;
        nxt_board[ny][nx] = i;
        return;
    }
}

void move_all_shark() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            nxt_board[i][j] = -1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j].is_shark_in) {
                move_shark(board[i][j].shark_i, j, i);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (nxt_board[i][j] < 0) {
                board[i][j].is_shark_in = false;
            } else {
                board[i][j].is_shark_in = true;
                board[i][j].shark_i = nxt_board[i][j];
            }
        }
    }
}

int count_shark() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j].is_shark_in) ret++;
        }
    }
    return ret;
}

void decrease_time() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j].is_shark_in) {
                board[i][j].t = k;
            } else if (board[i][j].t > 0) {
                board[i][j].t--;
            }
        }
    }
}

int solve() {
    for (int t = 1; t <= 1000; t++) {
        // 상어가 움직인다
        move_all_shark();
        // 상어가 한마리 남았는지 확인한다
        if (count_shark() == 1) {
            return t;
        }
        // 냄새의 시간을 줄인다
        decrease_time();
    }
    return -1;
}

int main() {
    cin >> N >> M >> k;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int s;
            cin >> s;
            if (s == 0) continue;
            board[y][x].is_shark_in = true;
            board[y][x].shark_i = s - 1;
            board[y][x].t = k;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> shark_array[i].d;
        shark_array[i].d--;
    }
    for (int i = 0; i < M; i++) {
        for (int d1 = 0; d1 < 4; d1++) {
            for (int d2 = 0; d2 < 4; d2++) {
                cin >> shark_array[i].d_priority[d1][d2];
                shark_array[i].d_priority[d1][d2]--;
            }
        }
    }
    cout << solve() << '\n';
}