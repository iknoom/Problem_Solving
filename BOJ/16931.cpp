#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, M, board[100][100];

bool is_ok(int x, int y){
    return (0 <= x && x < M && 0 <= y && y < N);
}

int main() {
    fastio;
    cin >> N >> M;
    int answer = N * M * 2;
    int max_h = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            max_h = max(max_h, board[i][j]);
        }
    }
    for (int h = max_h; h > 0; h--) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (board[y][x] < h) {
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    int x1 = x + dx[k], y1 = y + dy[k];
                    if (!is_ok(x1, y1)) {
                        answer++;
                        continue;
                    }
                    if (board[y1][x1] < h) {
                        answer++;
                    }
                }
            }
        }
    }
    cout << answer << '\n';
}