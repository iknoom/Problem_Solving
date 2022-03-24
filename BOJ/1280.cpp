#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
const int SIZE = 200001;
const int MOD = 1e9 + 7;

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
    SegTree segTree1(SIZE + 1);
    SegTree segTree2(SIZE + 1);
    int N;
    cin >> N;
    vector<int> A(N);
    long long answer = 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i > 0) {
            long long left_cnt = segTree1.query(0, A[i] - 1);
            long long left_sum = segTree2.query(0, A[i] - 1);
            long long right_cnt = segTree1.query(A[i] + 1, SIZE);
            long long right_sum = segTree2.query(A[i] + 1, SIZE);
            long long cur = right_sum - right_cnt * A[i] - left_sum + left_cnt * A[i];
            cur %= MOD;
            answer = answer * cur;
            answer %= MOD;
        }
        segTree1.update(A[i], 1);
        segTree2.update(A[i], A[i]);
    }
    cout << answer << '\n';
}