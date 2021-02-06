#include <bits/stdc++.h>

using namespace std;
int N, B[10][10], ans[2];

void sol(int n, int k, int t) {
    for (int i = k; i < N * N; i ++) {
        int x = i % N, y = i / N;
        if ((x + y) % 2 == t) continue;
        if (B[y][x] == 1) {
            bool flag = false;
            for (int d = min(x, y); d > 0; d--) {
                if (B[y - d][x - d] == 2) {
                    flag = true;
                }
            }
            for (int d = min(N - x - 1, y); d > 0; d--) {
                if (B[y - d][x + d] == 2) {
                    flag = true;
                }
            }
            if (flag) continue;
            B[y][x] = 2;
            sol(n + 1, i + 1, t);
            ans[t] = max(ans[t], n + 1);
            B[y][x] = 1;
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        cin >> B[i][j];
    }
    sol(0, 0, 0);
    sol(0, 0, 1);
    cout << ans[0] + ans[1] << endl;
}