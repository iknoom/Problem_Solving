#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

struct SegTree {
    int start;
    vector<int> seg;

    SegTree(int N) {
        start = 1;
        while (start < N) {
            start *= 2;
        }
        seg.resize(start * 2, 0);
    }

    void upAll(vector<int> &arr) {
        for (auto &k : arr) {
            seg[start + k]++;
        }
        for (int i = start - 1; i > 0; i--) {
            seg[i] = seg[i * 2] + seg[i * 2 + 1];
        }
    }

    void down(int idx) {
        idx += start;
        seg[idx]--;
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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    SegTree segTree(N + 2);
    segTree.upAll(A);
    long long answer = 0;
    for (auto k : A) {
        answer += segTree.query(0, k - 1);
        segTree.down(k);
    }
    cout << answer << '\n';
}