#include<bits/stdc++.h>

using namespace std;
typedef long long Long;

Long B, n;
Long A[4000], preA[4001], preAA[4001];
double dp[31][4001];

double f(int l, int r, int n) {
    double ret = 0, S;
    S = preA[r + 1] - preA[l];
    ret += preAA[r + 1] - preAA[l];
    ret -= (double)2 * S * S / (double)n;
    ret += S * S / (double)n;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> B;
    cin >> n;
    for (int i = 0; i < B; i++) for (int j = 0; j < n; j++) {
            dp[i][j] = 1e18;
        }
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        preA[i + 1] = preA[i] + A[i];
        preAA[i + 1] = preAA[i] + A[i] * A[i];
    }

    for (int i = 0; i < n; i++) {
        dp[0][i] = f(0, i, i + 1);
    }

    for (int k = 1; k < B; k++) {
        for (int i = k; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[k][i] = min(dp[k][i], dp[k - 1][j - 1] + f(j, i, i - j + 1));
            }
        }
    }
    double answer = 1e18;
    for (int k = 0; k < B; k++) {
        answer = min(answer, dp[k][n - 1]);
    }
    printf("%.5lf", answer);
}