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

int N, cards[16];
long long dp[10][1<<16][10];
bool visited[10][1<<16];

void solve(long long bits, int n_bits, int last) {
    if (last == -1) {
        for (int i = 0; i < N; i++) {
            last = cards[i];
            long long next_bits = bits - (1 << i);
            solve(next_bits, n_bits - 1, last);
            for (int j = 0; j < last; j++) {
                dp[last][bits][j] += dp[last][next_bits][j];
            }
        }
        return;
    } else if (visited[last][bits]) {
        return;
    } else {
        for (int i = 0; i < N; i++) {
            if (!(bits & (1 << i))) {
                continue;
            }
            long long next_bits = bits - (1 << i);
            solve(next_bits, n_bits - 1, last);
            int diff = cards[i];
            for (int i = 0; i < n_bits - 1; i++) {
                diff *= 10;
                diff %= last;
            }
            for (int j = 0; j < last; j++) {
                dp[last][bits][(j + diff) % last] += dp[last][next_bits][j];
            }
        }
        visited[last][bits] = true;
    }
}

//void debug(long long all_bits) {
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            cout << dp[i][all_bits][j] << ' ';
//        }
//        cout << '\n';
//    }
//}

int main() {
    fastio;
    // input
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    // dp, visited
    for (int i = 0; i < 10; i++) {
        visited[i][0] = true;
        dp[i][0][0] = 1;
    }

    // solution
    long long all_bits = (1 << N) - 1;
    solve(all_bits, N, -1);
    long long success_cases = 0, all_cases = 0;
    for (int i = 0; i < 10; i++) {
        success_cases += dp[i][all_bits][0];
        for (int j = 0; j < 10; j++) {
            all_cases += dp[i][all_bits][j];
        }
    }
    cout.precision(8);
    cout << (double)success_cases/all_cases << '\n';

//    debug(all_bits);
}