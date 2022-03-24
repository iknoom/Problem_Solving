#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;

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

    void up(int idx) {
        idx += start;
        seg[idx]++;
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

vector<int> compress(int N, vector<int> &A) {
    vector<int> tmp = A;
    sort(all(tmp));
    unordered_map<int, int> toIdx;
    int cnt = 0;
    for (auto k : tmp) {
        if (toIdx.find(k) == toIdx.end()) {
            toIdx[k] = cnt++;
        }
    }
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        B[i] = toIdx[A[i]];
    }
    return B;
}

void solution() {
    int N;
    cin >> N;
    vector<pi> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
        points[i].second = -points[i].second;
    }
    sort(all(points));
    vector<int> y(N);
    for (int i = 0; i < N; i++) {
        y[i] = -points[i].second;
    }
    vector<int> compY = compress(N, y);

    SegTree segTree(N + 2);
    long long answer = 0;
    for (auto k : compY) {
        answer += segTree.query(k, N);
        segTree.up(k);
    }
    cout << answer << '\n';
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