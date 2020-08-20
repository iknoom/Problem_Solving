#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int A, B;
    string a, b;

    getline(cin, a);
    getline(cin, b);
    A = a.size();
    B = b.size();

    int ans = 0;
    for (int i = 0; i < B; i++) {
        int j = i, cnt = 0;
        while (j < A - B + 1) {
            bool flag = true;
            for (int k = 0; k < B; k++) {
                if (a[j + k] != b[k]) {
                    flag = false;
                }
            }
            if (flag) {
                cnt++;
                j += B;
            }
            else {
                j++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}