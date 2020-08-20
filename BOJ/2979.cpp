#include <bits/stdc++.h>

using namespace std;
int a[3], b[3], p[4];
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> p[1] >> p[2] >> p[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i] >> b[i];
    }

    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        int t = 0;
        for (int j = 0; j < 3; j++){
            if (a[j] <= i && i < b[j]) t++;
        }
        ans += p[t] * t;
    }
    cout << ans << endl;
}