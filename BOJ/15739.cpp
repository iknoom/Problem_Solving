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
int N, arr[100][100];

bool det() {
    set<int> S;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] < 1) return false;
            if (arr[i][j] > N * N) return false;
            S.insert(arr[i][j]);
        }
    }
    if ((int)S.size() != N * N) return false;

    int X = 0;
    for (int i = 0; i < N; i++) X += arr[0][i];
    for (int i = 0; i < N; i++) {
        int row = 0, col = 0;
        for (int j = 0; j < N; j++) {
            row += arr[i][j];
            col += arr[j][i];
        }
        if (X != row) return false;
        if (X != col) return false;
    }
    int d1 = 0, d2 = 0;
    for (int i = 0; i < N; i++) {
        d1 += arr[i][i];
        d2 += arr[i][N - i - 1];
    }
    if (X != d1) return false;
    if (X != d2) return false;
    return true;
}

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    if (det()) cout << "TRUE" << '\n';
    else cout << "FALSE" << '\n';
}