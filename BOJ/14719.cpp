#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int board[500][500];

int main() {
    fastio;
    int H, W;
    cin >> H >> W;
    for (int w = 0; w < W; w++) {
        int h;
        cin >> h;
        for (int i = 0; i < h; i++) {
            board[i][w] = 1;
        }
    }
    // ->
    for (int i = 0; i < H; i++) {
        if (board[i][0] > 0) continue;
        for (int j = 0; j < W; j++) {
            if (board[i][j] > 0) break;
            board[i][j] = 2;
        }
    }
    // <-
    for (int i = 0; i < H; i++) {
        if (board[i][W - 1] > 0) continue;
        for (int j = W - 1; j >= 0; j--) {
            if (board[i][j] > 0) break;
            board[i][j] = 2;
        }
    }
    int answer = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (board[i][j] == 0) {
                answer++;
            }
        }
    }
    cout << answer << '\n';
}