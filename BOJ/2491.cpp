#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int ans = 1, cnt = 1;
    for (int i = 1; i < N; i++) {
        if (v[i - 1] <= v[i]) {
            cnt++; ans = max(ans, cnt);
        } else {
            cnt = 1;
        }
    }
    cnt = 1;
    for (int i = 1; i < N; i++) {
        if (v[i - 1] >= v[i]) {
            cnt++; ans = max(ans, cnt);
        } else {
            cnt = 1;
        }
    }

    cout << ans << '\n';
}