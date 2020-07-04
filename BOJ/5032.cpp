#include <bits/stdc++.h>

using namespace std;

int main() {
    int e, f, c, s, r, ans;
    cin >> e >> f >> c;
    s = e + f;
    ans = 0;
    while (s >= c){
        ans += s / c;
        r = s % c;
        s /= c;
        s += r;
    }
    cout << ans << endl;
}