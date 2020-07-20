#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin >> n >> m;
    priority_queue<long long> hq;
    for (int i = 0; i < n; i++){
        long long tmp; cin >> tmp;
        hq.push(-tmp);
    }

    for (int i = 0; i < m; i++){
        long long a, b;
        a = hq.top(); hq.pop();
        b = hq.top(); hq.pop();
        hq.push(a + b);
        hq.push(a + b);
    }

    long long ans = 0;
    while (!hq.empty()) {
        ans += hq.top(); hq.pop();
    }
    cout << -ans << '\n';
}