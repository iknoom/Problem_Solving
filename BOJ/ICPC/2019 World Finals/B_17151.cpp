#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

struct point{
    long long x, y;
} points[10001];

int n, left_arch[10001], right_arch[10001];
long long h, alpha, beta, dp[10001];

bool in_circle(long long x, long long y, long long d){
    if(2 * y > d || 2 * x > d) return true;
    return (2 * x - d) * (2 * x - d) + (2 * y - d) * (2 * y - d) <= d * d;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n >> h >> alpha >> beta;
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    for(int i = 0; i < n - 1; i++){
        int k = n - 1;
        for(int j = i + 1; j < n; j++){
            while(i < k) {
                long long d, dx, dy;
                d = points[k].x - points[i].x;
                dx = points[j].x - points[i].x;
                dy = h - points[j].y;
                if(2 * h < d + 2 * points[i].y || 2 * h < d + 2 * points[k].y) k--;
                else if(!in_circle(dx, dy, d)) k--;
                else break;
            }
        }
        left_arch[i] = k;
    }

    for(int i = n - 1; i > 0; i--){
        int k = 0;
        for(int j = i - 1; j >= 0; j--){
            while(i > k) {
                long long d, dx, dy;
                d = points[i].x - points[k].x;
                dx = points[i].x - points[j].x;
                dy = h - points[j].y;
                if(2 * h < d + 2 * points[i].y || 2 * h < d + 2 * points[k].y) k++;
                else if(!in_circle(dx, dy, d)) k++;
                else break;
            }
        }
        right_arch[i] = k;
    }

    fill(dp, dp + n, INF);
    dp[0] = alpha * (h - points[0].y);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(left_arch[j] < i || j < right_arch[i]) continue;
            long long d = points[i].x - points[j].x;
            dp[i] = min(dp[i], dp[j] + beta * d * d);
        }
        dp[i] += alpha * (h - points[i].y);
    }

    if(dp[n - 1] >= INF){
        cout << "impossible" << '\n';
    }
    else{
        cout << dp[n - 1] << '\n';
    }
}