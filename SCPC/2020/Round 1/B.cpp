#include <bits/stdc++.h>
using namespace std;

int n, k, X[3001], Y[3001];
int dp_lose[3001][3001];

void solution() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> X[i];
    for (int i = 1; i <= n; i++) cin >> Y[i];
    memset(dp_lose, 0, sizeof(dp_lose));

    int win = 0, lose = 0;

    int a_i = 0, col_asum = 0, col_bsum = 0;
    vector<int> col_window(n + 1);
    for (int b_i = 0; b_i <= n; b_i++) {
        // == update column window =================================
        // right window (b_i)
        col_bsum += Y[b_i];
        // left window (a_i)
        while (col_bsum - col_asum > k) {
            for (int j = 0; j <= n; j++) col_window[j] -= dp_lose[a_i][j];
            a_i += 1;
            col_asum += Y[a_i];
        }

        // == init index 0 ======================================
        if (b_i == 0){
            win++;
        }
        else {
            if (col_window[0] == 0) {
                dp_lose[b_i][0] = 1;
                col_window[0]++;
                lose++;
            }
            else {
                win++;
            }
        }
        // == slide row ===========================================
        int a_j = 0, row_asum = 0, row_bsum = 0, row_window = dp_lose[b_i][0];
        for (int b_j = 1; b_j <= n; b_j++) {
            // == update row window ==
            // right window (b_j)
            row_bsum += X[b_j];
            // left window (a_j)
            while (row_bsum - row_asum > k) {
                row_window -= dp_lose[b_i][a_j];
                a_j += 1;
                row_asum += X[a_j];
            }
            // fill dp
            if (row_window + col_window[b_j] == 0) {
                dp_lose[b_i][b_j] = 1;
                col_window[b_j]++;
                row_window++;
                lose++;
            }
            else {
                win++;
            }
        }

    }
    cout << win  << ' ' << lose << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T, test_case;

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cout << "Case #" << test_case+1 << endl;
        solution();
    }
    return 0;
}