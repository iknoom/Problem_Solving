#include <bits/stdc++.h>

using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
bool vst[1001][1001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int C, R, K, x = 0, y = 0;
    cin >> C >> R >> K;
    if (R * C < K) {
        cout << 0 << endl;
        return 0;
    }
    int i = 0;
    vst[0][0] = true;
    while (--K) {
        x += dx[i]; y += dy[i];
        vst[x][y] = true;

        int x0, y0;
        x0 = x + dx[i]; y0 = y + dy[i];
        if (vst[x0][y0] || x0 < 0 || C <= x0 || y0 < 0 || R <= y0) i = (i + 1) % 4;
    }
    cout << x + 1 << ' ' << y + 1 << endl;
}