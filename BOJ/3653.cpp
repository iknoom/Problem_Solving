#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
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

void solution() {
    int N, M;
    cin >> N >> M;
    vector<int> idx(N);
    iota(all(idx), M);
    SegTree segTree(N + M + 1);
    for (int i = 0; i < N; i++) {
        segTree.update(M + i, 1);
    }
    for (int i = 0; i < M; i++) {
        int cur;
        cin >> cur;
        cur--;
        cout << segTree.query(0, idx[cur] - 1) << ' ';
        segTree.update(idx[cur], -1);
        idx[cur] = M - i - 1;
        segTree.update(idx[cur], +1);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}