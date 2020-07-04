#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;
pi houses[300000];
int L_min_dp[300000], L_max_dp[300000];
int R_min_dp[300000], R_max_dp[300000];
int n;

bool decision(double d) {
    int i = 0, j = 0;
    while (j < n) {
        if (houses[j].first - houses[i].first <= 2.0 * d)
            j++;
        else {
            j--;
            break;
        }
    }
    while (true) {
        int LR_min = 0, LR_max = 0;

        if (0 < i && j < n - 1) {
            LR_min = min(L_min_dp[i - 1], R_min_dp[j + 1]);
            LR_max = max(L_max_dp[i - 1], R_max_dp[j + 1]);
        }
        else if (0 < i) {
            LR_min = L_min_dp[i - 1];
            LR_max = L_max_dp[i - 1];
        }
        else if (j < n - 1) {
            LR_min = R_min_dp[j + 1];
            LR_max = R_max_dp[j + 1];
        }

        if (LR_max - LR_min <= 2 * d)
            return true;
        j++;
        if (j < n) {
            while (houses[j].first - houses[i].first > 2 * d)
                i++;
        }
        else
            break;
    }
    return false;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> houses[i].first >> houses[i].second;
    }
    sort(houses, houses + n);

    int L_min = 1e9, L_max = -1e9;
    int R_min = 1e9, R_max = -1e9;
    for (int i = 0; i < n; i++) {
        L_min = min(L_min, houses[i].second);
        L_max = max(L_max, houses[i].second);
        R_min = min(R_min, houses[n - 1 - i].second);
        R_max = max(R_max, houses[n - 1 - i].second);
        L_min_dp[i] = L_min; L_max_dp[i] = L_max;
        R_min_dp[n - 1 - i] = R_min; R_max_dp[n - 1 - i] = R_max;
    }

    double L = 0, R = 1e9;
    int test = 37;
    while (test--) {
        double mid = (L + R) / 2;
        if (decision(mid))
            R = mid;
        else
            L = mid;
    }

    printf("%.1lf\n", R);
}