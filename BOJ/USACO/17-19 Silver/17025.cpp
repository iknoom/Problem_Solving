#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pi = pair<int, int>;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int N, B[1000][1000];
bool vst[1000][1000];
int S, P;

void bfs(int y, int x) {
    queue<pi> q;
    int s_cnt = 0, p_cnt = 0;
    q.push({ x, y });

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        s_cnt++;

        for (int i = 0; i < 4; i++) {
            int xx = a + dx[i];
            int yy = b + dy[i];
            if (0 <= xx && xx < N && 0 <= yy && yy < N && B[yy][xx]) {
                if (!vst[yy][xx]) {
                    vst[yy][xx] = true;
                    q.push({ xx, yy });
                }
            }
            else
                p_cnt++;
        }
    }
    if (S == s_cnt) {
        P = min(P, p_cnt);
    }
    if (S < s_cnt) {
        S = s_cnt; P = p_cnt;
    }
}


int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    cin.get();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c = cin.get();
            if (c == '#') B[i][j] = 1;
        }
        cin.get();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] && !vst[i][j]) {
                vst[i][j] = true;
                bfs(i, j);
            }
        }
    }
    cout << S << " " << P << endl;
}
