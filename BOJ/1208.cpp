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
const int SIZE = 2000000;
int sum_count[2][SIZE * 2 + 1], N, S, A, B, arr[40];

void fill_sum_count(int start, int n, int i) {
    for (int j = 0; j < (1 << n); j++) {
        int cur_S = 0;
        for (int k = 0; k < n; k++) {
            if (j & (1 << k)) {
                cur_S += arr[start + k];
            }
        }
        sum_count[i][cur_S + SIZE]++;
    }
}

int main() {
    fastio;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    A = N / 2;
    B = N - A;
    fill_sum_count(0, A, 0);
    fill_sum_count(A, B, 1);
    long long answer = 0;
    for (int i = 0; i < SIZE * 2 + 1; i++) {
        int a = i - SIZE;
        int b = S - a;
        if (b < -SIZE || b > SIZE) continue;
        long long cur = (long long)sum_count[0][a + SIZE] * sum_count[1][b + SIZE];
        if (cur) {
//            cout << a << ' ' << b << '\n';
            answer += cur;
        }
    }
    if (S == 0) {
        answer--;
    }
    cout << answer << '\n';
}