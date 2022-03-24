#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    int start;
    vector<long long> seg;

    SegTree(int N) {
        start = 1;
        while (start < N) {
            start *= 2;
        }
        seg.resize(start * 2, 0);
    }

    void update(int idx, long long diff) {
        idx += start;
        seg[idx] += diff;
        while (idx > 0) {
            idx /= 2;
            seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
        }
    }

    long long query(int l, int r) {
        l += start;
        r += start;
        long long ret = 0;
        while (l <= r) {
            if (r % 2 == 0) {
                ret += seg[r--];
            }
            if (l % 2 == 1) {
                ret += seg[l++];
            }
            l /= 2;
            r /= 2;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<int> flower(N + 2);
    flower[0] = -1;
    flower[N + 1] = -1;
    for (int i = 1; i <= N; i++) {
        cin >> flower[i];
    }
    SegTree segTree(N + 2);
    for (int i = 1; i <= N; i++) {
        if (flower[i - 1] != flower[i]) {
            segTree.update(i, 1);
        }
    }
    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            cout << 1 + segTree.query(a + 1, b) << '\n';
        } else {
            if (flower[a - 1] != flower[a]) {
                segTree.update(a, -1);
            }
            if (flower[a] != flower[a + 1]) {
                segTree.update(a + 1, -1);
            }
            flower[a] = b;
            if (flower[a - 1] != flower[a]) {
                segTree.update(a, 1);
            }
            if (flower[a] != flower[a + 1]) {
                segTree.update(a + 1, 1);
            }
        }
    }
}