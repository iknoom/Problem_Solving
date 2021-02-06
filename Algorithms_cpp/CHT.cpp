#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1000001;

/* 교점을 분수로 보관
struct LinearFunc {
    long long a, b, u, d;
    LinearFunc(): LinearFunc(1, 0){}
    LinearFunc(long long a1, long long b1): a(a1), b(b1), u(-1e18), d(1){}
};

bool cross_after(LinearFunc &f, LinearFunc &g) {
    g.u = f.b - g.b;
    g.d = g.a - f.a;
    if (g.d < 0) {
        g.d = -g.d;
        g.u = -g.u;
    }
    return f.u * g.d < g.u * f.d;
}
 */

struct LinearFunc {
    long long a, b;
    double s;
    LinearFunc(): LinearFunc(1, 0){}
    LinearFunc(long long a1, long long b1): a(a1), b(b1), s(-1e9){}
};

double cross(LinearFunc &f, LinearFunc &g) {
    return (g.b - f.b) / (f.a - g.a);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    long long n, a[MAX_SIZE], b[MAX_SIZE];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // dp[i] = b[j]a[i] + dp[j]
    long long dp[MAX_SIZE];
    vector<LinearFunc> stack;

    for(int i = 1; i < n; i++){
        // 새로운 직선을 스택에 push
        LinearFunc g(b[i-1], dp[i-1]);
        while(!stack.empty()){
            // 교점을 구하면서 교점이 뒤에 있는지 검사함
            g.s = cross(stack.back(), g);
            if(stack.back().s < g.s) break;
            stack.pop_back();
        }
        stack.push_back(g);

        long long x = a[i];
        int pos;
        if(x < stack.back().s){
            // x에 해당하는 선분을 이분 탐색으로 찾음
            int lo = 0, hi = stack.size() - 1;
            while(lo + 1 < hi){
                int mid = (lo+hi)/2;
                (x < stack[mid].s ? hi : lo) = mid;
            }
            pos = lo;
        } else {
            // 마지막 선분
            pos = stack.size() - 1;
        }
        // dp 값 계산
        dp[i] = stack[pos].a * x + stack[pos].b;
    }

    cout << dp[n-1] << '\n';
}