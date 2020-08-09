#include <bits/stdc++.h>
using namespace std;

struct Node{
    long long s, m, l, r;
    Node() : s(0), m(0), l(0), r(0) { }
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

    void init() {
        data.clear();
        data.resize(n * 2);
    }

    void set(int i, long long v) {
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

    void update(int i, long long v) {
        int k = i + n - 1;
        data[k].s += v;
        data[k].l += v;
        data[k].r += v;
        data[k].m += v;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = data[k * 2 + 1] + data[k * 2 + 2];
        }
    }

    long long query(int l, int r){
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

struct point{
    int x, y; long long w;
    point(int x, int y, long long w) : x(x), y(y), w(w) { }
    bool operator<(point &other) {
        return y < other.y;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<point> v;
    set<int> x_cords, y_cords;
    unordered_map<int, int> x_i, y_i;


    int N1;
    cin >> N1;
    for (int i = 0; i < N1; i++) {
        int x, y;
        cin >> x >> y;
        x_cords.insert(x);
        y_cords.insert(y);
        v.emplace_back(x, y, 1);
    }
    int N2;
    cin >> N2;
    for (int i = 0; i < N2; i++) {
        int x, y;
        cin >> x >> y;
        x_cords.insert(x);
        y_cords.insert(y);
        v.emplace_back(x, y, -1);
    }
    sort(v.begin(), v.end());
    long long c1, c2;
    cin >> c1 >> c2;

    int idx = 0;
    for (auto it = x_cords.begin(); it != x_cords.end(); it++) {
        x_i[*it] = idx++;
    }
    idx = 0;
    for (auto it = y_cords.begin(); it != y_cords.end(); it++) {
        y_i[*it] = idx++;
    }

    int X = x_cords.size();
    int Y = y_cords.size();
    int N = N1 + N2;
    SegmentTree Seg = SegmentTree(X);

    int p = 0, q;
    long long ans = -1e18;
    for (int i = 0; i < Y; i++) {
        Seg.init();
        q = p;
        for (int j = i; j < Y; j++) {
            while (q < N && y_i[v[q].y] == j) {
                if (v[q].w == 1) Seg.update(x_i[v[q].x], c1);
                else Seg.update(x_i[v[q].x], -c2);
                q++;
            }
            ans = max(ans, Seg.query(0, X - 1));
        }
        while (p < N && y_i[v[p].y] == i) p++;
    }
    cout << ans << '\n';
}