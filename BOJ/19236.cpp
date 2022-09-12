#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct fish {
    int a, b, x, y;
    bool alive;
} fish_array[16];

int board[4][4];
int answer;

bool is_movable(fish fish0) {
    int nx = fish0.x + dx[fish0.b];
    int ny = fish0.y + dy[fish0.b];
    if (nx < 0 || nx >= 4) return false;
    if (ny < 0 || ny >= 4) return false;
    if (board[ny][nx] < 0) return false;
    return true;
}

void move(int i) {
    while (!is_movable(fish_array[i])) {
        fish_array[i].b = (fish_array[i].b + 1) % 8;
    }
    int nx = fish_array[i].x + dx[fish_array[i].b];
    int ny = fish_array[i].y + dy[fish_array[i].b];
    // 위치를 바꾼다.
    int j = board[ny][nx];
    board[ny][nx] = i;
    board[fish_array[i].y][fish_array[i].x] = j;
    fish_array[j].x = fish_array[i].x;
    fish_array[j].y = fish_array[i].y;
    fish_array[i].x = nx;
    fish_array[i].y = ny;
}

void solve(fish shark, int score) {
    // 답을 갱신한다.
    answer = max(answer, score);

    // 현재 상태를 저장한다.
    fish before_fish_array[16];
    for (int i = 0; i < 16; i++) {
        before_fish_array[i] = fish_array[i];
    }

    // 물고기가 움직인다. 상어가 있는 곳으로는 움직일 수 없다.
    board[shark.y][shark.x] = -1;
    for (int i = 0; i < 16; i++) {
        if (!fish_array[i].alive) continue;
        move(i);
    }
    board[shark.y][shark.x] = shark.a;

    // 상어가 잡을 수 있는 물고기를 구한다.
    vector<int> next_fish_idx;
    while (is_movable(shark)) {
        shark.x += dx[shark.b];
        shark.y += dy[shark.b];
        int i = board[shark.y][shark.x];
        if (fish_array[i].alive) {
            next_fish_idx.push_back(i);
        }
    }
    // 선택할 수 있는 물고기 중 하나를 선택한다. (백트래킹)
    for (int idx : next_fish_idx) {
        fish_array[idx].alive = false;
        solve(fish_array[idx], score + idx + 1);
        fish_array[idx].alive = true;
    }

    // 모두 복원한다.
    for (int i = 0; i < 16; i++) {
        fish_array[i] = before_fish_array[i];
        fish fish0 = fish_array[i];
        board[fish0.y][fish0.x] = i;
    }
}

int main() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            fish_array[a] = {a, b, x, y, true};
            board[y][x] = a;
        }
    }
    int idx = board[0][0];
    fish_array[idx].alive = false;
    solve(fish_array[idx], idx + 1);
    cout << answer << '\n';
}