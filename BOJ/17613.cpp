#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int max_jump_number(int l, int r) {
    if (r == 0) {
        return 0;
    }
    if (r == 1) {
        return 1;
    }
    int jump_dist = 1, jump_cnt = 0;
    while (jump_dist - 1 <= r) {
        jump_dist *= 2;
        jump_cnt++;
    }
    int nxt_l = jump_dist / 4 - 1;
    int nxt_m = jump_dist / 2 - 1;
    int nxt_r = jump_dist - 1;
    if (nxt_m <= l) {
        int ret = (jump_cnt - 1) + max_jump_number(l - nxt_m, r - nxt_m);
        return ret;
    }
    else {
        int ret1, ret2;
        ret1 = (jump_cnt - 1) + max_jump_number(0, r - nxt_m);
        ret2 = (jump_cnt - 2) + max_jump_number(max(0, l - nxt_l), nxt_m - nxt_l - 1);
        return max(ret1, ret2);
    }
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        cout << max_jump_number(l, r) << '\n';
    }
}