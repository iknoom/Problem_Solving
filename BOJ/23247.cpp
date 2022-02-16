#include <bits/stdc++.h>
using namespace std;
int m, n, arr[300][300];

int get_ten(int r, int c) {
    int ret = 0;
    vector<pair<int, int>> hw = {
            {1,  10},
            {2,  5},
            {5,  2},
            {10, 1},
            {1,  9},
            {3,  3},
            {9,  1},
            {1,  8},
            {2,  4},
            {4,  2},
            {8,  1},
            {1,  7},
            {7,  1},
            {1,  6},
            {2,  3},
            {3,  2},
            {6,  1},
            {1,  5},
            {5,  1},
            {1,  4},
            {2,  2},
            {4,  1},
            {1,  3},
            {3,  1},
            {1,  2},
            {2,  1},
            {1,  1}
    };
    for (auto [h, w] : hw) {
        if (r + h > m) continue;
        if (c + w > n) continue;
        int cur = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cur += arr[r + i][c + j];
            }
        }
        if (cur == 10) {
            ret++;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int answer = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            answer += get_ten(i, j);
        }
    }
    cout << answer << '\n';
}