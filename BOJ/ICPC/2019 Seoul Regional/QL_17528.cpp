#include <iostream>
#include <algorithm>
using namespace std;
int n, Sb, ans;
int A[250], B[250], dp[251][62501];
int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n;
    Sb = 0;
    ans = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i];
        Sb += B[i];
    }
    fill(dp[0], dp[0] + 62501, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 62500; j++) {
            dp[i + 1][j] = dp[i][j];
            if (A[i] <= j)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - A[i]] + B[i]);
            ans = min(ans, max(Sb - dp[i + 1][j], j));
        }
    }
    cout << ans << endl;
}