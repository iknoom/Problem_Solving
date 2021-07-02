#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

const int dr[] = {0, 0, -1, 1};
const int dc[] = {1, -1, 0, 0};
int N, K, board[12][12], row[12], col[12], dir[12];
vector<int> pieces[12][12];

bool is_four(int cur) {
    return sz(pieces[row[cur]][col[cur]]) >= 4;
}

bool is_in_board(int r, int c) {
    return (0 <= r && r < N && 0 <= c && c < N);
}

void move_piece(int i) {
    int nxt_r = row[i] + dr[dir[i]];
    int nxt_c = col[i] + dc[dir[i]];
    vector<int> stk;
    // pieces to stack
    while (!pieces[row[i]][col[i]].empty()) {
        int j = pieces[row[i]][col[i]].back();
        pieces[row[i]][col[i]].pop_back();
        stk.push_back(j);
        if (i == j) {
            break;
        }
    }
    // blue, out
    if (!is_in_board(nxt_r, nxt_c) || board[nxt_r][nxt_c] == 2) {
        dir[i] ^= 1;
        nxt_r = row[i] + dr[dir[i]];
        nxt_c = col[i] + dc[dir[i]];
        if (!is_in_board(nxt_r, nxt_c) || board[nxt_r][nxt_c] == 2) {
            while (!stk.empty()) {
                int j = stk.back();
                stk.pop_back();
                pieces[row[i]][col[i]].push_back(j);
            }
            return;
        }
    }
    // red
    if (board[nxt_r][nxt_c] == 1) {
        reverse(all(stk));
    }
    // stack to pieces
    while (!stk.empty()) {
        int j = stk.back();
        stk.pop_back();
        row[j] = nxt_r;
        col[j] = nxt_c;
        pieces[nxt_r][nxt_c].push_back(j);
    }
}

int solution(){
    for (int turn = 1; turn <= 1000; turn++) {
        for (int i = 0; i < K; i++) {
            move_piece(i);
            if (is_four(i)) {
                return turn;
            }
        }
    }
    return -1;
}

int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        r--; c--; d--;
        row[i] = r; col[i] = c; dir[i] = d;
        pieces[r][c].push_back(i);
    }
    cout << solution() << '\n';
}