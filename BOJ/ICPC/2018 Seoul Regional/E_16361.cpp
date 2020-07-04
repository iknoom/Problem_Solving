#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
using pi = pair<int, int>;
const int MAX = 300000;
int N, max_dp[MAX], min_dp[MAX];
pi P[MAX];

bool check(int E) {
    int V2 = 0;
    while (V2 < N && P[V2].second <= E / 2) V2++;
    if (N - 1 <= V2) return true;
    if (P[0].first == 0 && V2 == 0) return false;
    int B_min = 1e9, B_max = 0;
    while (V2 < N - 1) {
        B_min = min(B_min, P[V2].second);
        B_max = max(B_max, P[V2].second);
        int B_error = B_max - B_min;
        double L1 = B_max - E / 2.0;

        int C_min = min_dp[V2 + 1];
        int C_max = max_dp[V2 + 1];
        int C_error = C_max - C_min;
        double L2 = C_min + E / 2.0;
        if (B_error <= E && C_error <= E && L1 <= L2)
            return true;
        V2++;
    }
    return false;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }
    sort(P, P + N);
    int l_min = 1e9, l_max = 0;
    for (int i = N - 1; i >= 0; i--) {
        l_min = min(l_min, P[i].second);
        l_max = max(l_max, P[i].second);
        min_dp[i] = l_min;
        max_dp[i] = l_max;
    }

    if (N == 1) {
        if (P[0].first == 0) printf("%.1f\n", (double)P[0].second);
        else printf("%.1f\n", 0.0);
        return 0;
    }

    int L = 0, R = 1e9;
    if (P[0].first == 0) L = P[0].second;
    L -= 1;

    while (L + 1 < R) {
        int mid = (L + R) >> 1;
        if (check(mid)) R = mid;
        else L = mid;
    }
    printf("%.1f\n", R / 2.0);
}
