#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool is_ok(vector<vector<int>> &board, vector<int> &loc) {
    if (loc[0] < 0 || (int)board.size() <= loc[0]) {
        return false;
    }
    if (loc[1] < 0 || (int)board.back().size() <= loc[1]) {
        return false;
    }
    if (board[loc[0]][loc[1]] == 0) {
        return false;
    }
    return true;
}

pi dfs(vector<vector<int>> &board, vector<int> &aloc, vector<int> &bloc, int turn, int cnt) {
    if (turn == 0 && board[aloc[0]][aloc[1]] == 0) {
        return {cnt, turn ^ 1};
    }
    if (turn == 1 && board[bloc[0]][bloc[1]] == 0) {
        return {cnt, turn ^ 1};
    }

    vector<int> win, lose;
    if (turn == 0) {
        board[aloc[0]][aloc[1]] = 0;
        for (int i = 0; i < 4; i++) {
            aloc[0] += dy[i];
            aloc[1] += dx[i];
            if (is_ok(board, aloc)) {
                pi ret = dfs(board, aloc, bloc, turn ^ 1, cnt + 1);
                if (ret.second == turn) {
                    win.push_back(ret.first);
                } else {
                    lose.push_back(ret.first);
                }
            }
            aloc[0] -= dy[i];
            aloc[1] -= dx[i];
        }
        board[aloc[0]][aloc[1]] = 1;
    } else if (turn == 1) {
        board[bloc[0]][bloc[1]] = 0;
        for (int i = 0; i < 4; i++) {
            bloc[0] += dy[i];
            bloc[1] += dx[i];
            if (is_ok(board, bloc)) {
                pi ret = dfs(board, aloc, bloc, turn ^ 1, cnt + 1);
                if (ret.second == turn) {
                    win.push_back(ret.first);
                } else {
                    lose.push_back(ret.first);
                }
            }
            bloc[0] -= dy[i];
            bloc[1] -= dx[i];
        }
        board[bloc[0]][bloc[1]] = 1;
    }

    // return answer
    if (win.empty() && lose.empty()) {
        return {cnt, turn ^ 1};
    }
    if (!win.empty()) {
        return {*min_element(win.begin(), win.end()), turn};
    }
    return {*max_element(lose.begin(), lose.end()), turn ^ 1};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    pi answer = dfs(board, aloc, bloc, 0, 0);
    return answer.first;
}

int main() {
    cout << solution({{1, 1, 1},
                      {1, 0, 1},
                      {1, 1, 1}}, {1, 0}, {1, 2}) << '\n';

}