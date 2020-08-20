#include <bits/stdc++.h>

using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int R, C, o, v;
string B[255];
bool vst[255][255];

struct node{
    int x, y;
    node(int x, int y) : x(x), y(y) { }
};

void bfs(int y, int x) {
    queue<node> q;
    vst[y][x] = true;
    q.push({x, y});
    int t_o = 0, t_v = 0;
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if (B[t.y][t.x] == 'o') t_o++;
        if (B[t.y][t.x] == 'v') t_v++;
        for (int i = 0; i < 4; i++) {
            int x1, y1;
            x1 = t.x + dx[i];
            y1 = t.y + dy[i];
            if (0 <= x1 && x1 < C && 0 <= y1 && y1 < R && !vst[y1][x1] && B[y1][x1] != '#') {
                vst[y1][x1] = true;
                q.push({x1, y1});
            }
        }
    }
    if (t_o > t_v) {
        o += t_o;
    }
    else {
        v += t_v;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> B[i];

    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        if (B[i][j] != '#' && !vst[i][j]) {
            bfs(i, j);
        }
    }

    cout << o << ' ' << v << endl;
}