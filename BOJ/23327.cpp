#include <bits/stdc++.h>

using namespace std;
typedef long long Long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<Long> S(1), SS(1);
    for (int i = 0; i < N; i++) {
        Long a_i;
        cin >> a_i;
        S.push_back(S.back() + a_i);
        SS.push_back(SS.back() + a_i * a_i);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        Long x = S[r] - S[l - 1];
        Long y = SS[r] - SS[l - 1];
        cout << (x * x - y) / 2 << '\n';
    }
}