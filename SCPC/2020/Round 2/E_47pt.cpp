#include <bits/stdc++.h>
using namespace std;

int n, dp[305];

int solution() {
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        int a, b;
        cin >> a >> b;
    }
    return dp[n];
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    dp[3] = 0;
    dp[4] = 1;
    for (int i = 5; i < 302; i++)
        dp[i] = dp[(i+1)>>1]+2;


    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cout << "Case #" << test_case+1 << '\n';
        cout << solution() << '\n';
    }
    return 0;
}