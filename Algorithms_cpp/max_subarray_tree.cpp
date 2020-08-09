#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Node{
    int s, m, l, r;
    Node() : s(0), m(-INF), l(-INF), r(-INF) { }
    Node operator+(Node &right) {
        Node ret;
        ret.s = s + right.s;
        ret.l = max(l, s + right.l);
        ret.r = max(right.r, r + right.s);
        ret.m = max(r + right.l, max(m, right.m));
        return ret;
    }
};

struct SegmentTree{
    vector<Node> data;
    int n;
    SegmentTree(int size) {
        int p = 1;
        while (p < size) p *= 2;
        data.resize(p * 2);
        n = p;
    }

    void set(int i, int v) {
        i += n - 1;
        data[i].s = v;
        data[i].l = v;
        data[i].r = v;
        data[i].m = v;
    }

    void build() {
        for (int i = n - 2; i >= 0; i--) {
            data[i] = data[i * 2 + 1] + data[i * 2 + 2];
        }
    }

    void update(int i, int v) {
        i += n - 1;
        set(i, v);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = data[i * 2 + 1] + data[i * 2 + 2];
        }
    }

    int query(int l, int r){
        l += n;
        r += n + 1;
        Node ret_l = Node();
        Node ret_r = Node();
        while (l < r) {
            if (r & 1) {
                r--;
                ret_r = data[r - 1] + ret_r;
            }
            if (l & 1) {
                ret_l = ret_l + data[l - 1];
                l++;
            }
            l >>= 1;
            r >>= 1;
        }
        return (ret_l + ret_r).m;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    SegmentTree Seg = SegmentTree(N);
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        Seg.set(i, v);
    }
    Seg.build();

    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << Seg.query(l - 1, r - 1) << '\n';
    }
}