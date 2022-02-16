#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {0, -1, 0, 1, 0};
const int dy[] = {0, 0, 1, 0, -1};
int N, board[10][10], vst[10][10], answer;

void dfs(int r, int c, int cnt, int cost) {
    if (cnt == 3) {
        answer = min(answer, cost);
        return;
    }
    for (int c1 = c; c1 < N - 1; c1++) {
        bool flag = true;
        for (int i = 0; i < 5; i++) {
            if (vst[r + dy[i]][c1 + dx[i]]) flag = false;
        }
        if (!flag) continue;
        int nxt_cost = cost;
        for (int i = 0; i < 5; i++) {
            vst[r + dy[i]][c1 + dx[i]] = 1;
            nxt_cost += board[r + dy[i]][c1 + dx[i]];
        }
        dfs(r, c1 + 2, cnt + 1, nxt_cost);
        for (int i = 0; i < 5; i++) {
            vst[r + dy[i]][c1 + dx[i]] = 0;
        }
    }
    for (int r1 = r + 1; r1 < N - 1; r1++) {
        for (int c1 = 1; c1 < N - 1; c1++) {
            bool flag = true;
            for (int i = 0; i < 5; i++) {
                if (vst[r1 + dy[i]][c1 + dx[i]]) flag = false;
            }
            if (!flag) continue;
            int nxt_cost = cost;
            for (int i = 0; i < 5; i++) {
                vst[r1 + dy[i]][c1 + dx[i]] = 1;
                nxt_cost += board[r1 + dy[i]][c1 + dx[i]];
            }
            dfs(r1, c1 + 2, cnt + 1, nxt_cost);
            for (int i = 0; i < 5; i++) {
                vst[r1 + dy[i]][c1 + dx[i]] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    answer = 1e9;
    dfs(1, 1, 0, 0);
    cout << answer << '\n';
}