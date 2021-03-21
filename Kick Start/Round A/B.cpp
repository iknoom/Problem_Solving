#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int solution() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A, lower, upper, hrz;
    for (int i = 0; i < N; i++) {
        vector<int> row(M), row1(M), row2(M), row3(M);
        for (int j = 0; j < M; j++) cin >> row[j];
        A.push_back(row);
        lower.push_back(row1);
        upper.push_back(row2);
        hrz.push_back(row3);
    }
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) {
        if (A[y][x]) {
            if (y && A[y - 1][x]) {
                lower[y][x] = lower[y - 1][x] + 1;
            }
            else {
                lower[y][x] = 1;
            }
        }
    }
    for (int y = N - 1; y >= 0; y--) for (int x = M - 1; x >= 0; x--) {
        if (A[y][x]) {
            if (y < N - 1 && A[y + 1][x]) {
                upper[y][x] = upper[y + 1][x] + 1;
            }
            else {
                upper[y][x] = 1;
            }
        }
    }


    int ret = 0;
    for (int y = 0; y < N; y++) for (int x = 0; x < M; x++) {
            if (A[y][x] == 0) continue;
            if (x and A[y][x - 1]) {
                hrz[y][x] = hrz[y][x - 1] + 1;
            }
            else {
                hrz[y][x] = 1;
            }
            // solution
            int L = 1;
            while (true) {
                L++;
                int H = L / 2;
                if (hrz[y][x] < L) break;
                // left
                // 2 L cases
                if (y - L * 2 + 1 >= 0 && lower[y][x - L + 1] >= L * 2)
                    ret += 1;
                if (y + L * 2 - 1 < N && upper[y][x - L + 1] >= L * 2)
                    ret += 1;
                if (L % 2 == 0 && H > 1 && y - H + 1 >= 0 && lower[y][x - L + 1] >= H)
                    ret += 1;
                if (L % 2 == 0 && H > 1 && y + H - 1 < N && upper[y][x - L + 1] >= H)
                    ret += 1;
                // right
                // 2 L cases
                if (y - L * 2 + 1 >= 0 && lower[y][x] >= L * 2)
                    ret += 1;
                if (y + L * 2 - 1 < N && upper[y][x] >= L * 2)
                    ret += 1;
                // 2 H cases
                if (L % 2 == 0 && H > 1 && y - H + 1 >= 0 && lower[y][x] >= H)
                    ret += 1;
                if (L % 2 == 0 && H > 1 && y + H - 1 < N && upper[y][x] >= H)
                    ret += 1;;
            }
    }
    return ret;
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int answer = solution();
        cout << "Case #" << c << ": " << answer << '\n';
    }
}