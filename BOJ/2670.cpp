#include <bits/stdc++.h>

using namespace std;
double A[10001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    double t = 0.0;
    cin >> N;
    for (int i = 0 ; i < N; i++) {
        cin >> A[i];
        t = max(t, A[i]);
    }
    if (t < 1.0L) {
        printf("%.3lf", t);
        return 0;
    }

    double ans = 1.0, cur = 1.0;
    for (int i = 0; i < N; i++) {
        cur = max(cur * A[i], 1.0);
        ans = max(ans, cur);
    }
    printf("%.3lf", ans);
}