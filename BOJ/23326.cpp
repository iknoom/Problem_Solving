#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    set<int> S;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            S.insert(i);
            S.insert(i + N);
        }
    }
    int cur = 0;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            i--;
            if (S.find(i) == S.end()) {
                S.insert(i);
                S.insert(i + N);
            } else {
                S.erase(S.find(i));
                S.erase(S.find(i + N));
            }
        } else if (t == 2) {
            int x;
            cin >> x;
            cur = (cur + x) % N;
        } else {
            if (S.empty()) {
                cout << -1 << '\n';
            } else {
                int a = *S.lower_bound(cur);
                int b = *S.upper_bound(cur);
                cout << min(abs(a - cur), abs(b - cur)) << '\n';
            }
        }
    }
}