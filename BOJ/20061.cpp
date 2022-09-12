#include <iostream>

using namespace std;

int answer = 0;
int board[2][6][4];

int sum_row(int idx, int y) {
    int ret = 0;
    for (int x = 0; x < 4; x++) {
        ret += board[idx][y][x];
    }
    return ret;
}

int sum_all(int idx) {
    int ret = 0;
    for (int y = 0; y < 6; y++) {
        ret += sum_row(idx, y);
    }
    return ret;
}

void shift(int idx, int y) {
    while (y) {
        for (int x = 0; x < 4; x++) {
            board[idx][y][x] = board[idx][y - 1][x];
        }
        y--;
    }
    for (int x = 0; x < 4; x++) {
        board[idx][0][x] = 0;
    }
}

void append(int idx, int type, int x) {
    // 블록을 넣는다. (type 1 : 한칸, type 2 : 세로, type 3 : 가로)
    int y = 1;
    while (y < 5) {
        if (board[idx][y + 1][x]) break;
        if (type == 3 && board[idx][y + 1][x + 1]) break;
        y++;
    }
    board[idx][y][x] = 1;
    if (type == 2) board[idx][y - 1][x] = 1;
    if (type == 3) board[idx][y][x + 1] = 1;
    // 한 행이 차는지 확인한다. 찼으면 답에 더한다. 그리고 shift 한다.
    y = 5;
    while (y >= 0) {
        if (sum_row(idx, y) == 4) {
            answer++;
            shift(idx, y);
        } else {
            y--;
        }
    }
    // 넘치는지 확인한다. 넘치면 shift 한다.
    while (sum_row(idx, 1) != 0) {
        shift(idx, 5);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    while (N--) {
        int t, x, y;
        cin >> t >> x >> y;
        append(0, t, x);
        append(1, t == 1 ? t : 5 - t, y);
    }
    cout << answer << '\n';
    cout << sum_all(0) + sum_all(1) << '\n';
}