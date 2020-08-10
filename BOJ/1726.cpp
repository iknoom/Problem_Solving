#include <bits/stdc++.h>
using namespace std;
const int dx[] = {1, 0, -1, 0,};
const int dy[] = {0, 1, 0, -1};
bool vst[101][101][4];
int N, M, board[101][101];

struct node {
    int x, y, d, t;
    node() : x(0), y(0), d(0), t(0) { }
    node(int x, int y, int d) : x(x), y(y), d(d), t(0) { }
};

int bfs(node S, node E) {
    queue<node> q;
    q.push(S);
    vst[S.y][S.x][S.d] = true;
    S.t = 0;

    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        //cout << cur.x << ' ' << cur.y << ' ' << cur.d << ' ' << cur.t << endl;
        if (cur.x == E.x && cur.y == E.y && cur.d == E.d){
            return cur.t;
        }
        vector<node> tmp;
        for (int i = 1; i <= 3; i++) {
            int x1, y1;
            x1 = cur.x + i * dx[cur.d];
            y1 = cur.y + i * dy[cur.d];
            if (board[y1][x1] == 1) break;
            tmp.emplace_back(x1, y1, cur.d);
        }
        tmp.emplace_back(cur.x, cur.y, cur.d + 1);
        tmp.emplace_back(cur.x, cur.y, cur.d - 1);

        for (auto nxt : tmp) {
            if (nxt.d >= 4) nxt.d -= 4;
            if (nxt.d < 0) nxt.d += 4;
            if (nxt.y >= N || nxt.x >= M) continue;
            if (nxt.y < 0 || nxt.x < 0) continue;
            if (!vst[nxt.y][nxt.x][nxt.d]){
                vst[nxt.y][nxt.x][nxt.d] = true;
                nxt.t = cur.t + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        cin >> board[i][j];
    }
    node S, E;
    cin >> S.y >> S.x >> S.d;
    cin >> E.y >> E.x >> E.d;
    S.x--; S.y--; S.d--;
    E.x--; E.y--; E.d--;
    if (S.d == 1 || S.d == 2) S.d = 3 - S.d;
    if (E.d == 1 || E.d == 2) E.d = 3 - E.d;

    cout << bfs(S, E) << endl;
}