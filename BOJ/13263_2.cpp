#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e18;

struct Line {
    long long a, b;
    Line(): a(0), b(-INF) {}
    Line(long long a1, long long b1): a(a1), b(b1) {}
    long long f(long long x) {
        return a * x + b;
    }
};

struct Node {
    int l, r;
    long long s, e;
    Line line;
    Node(int l1, int r1, long long s1, long long e1, Line line1) : l(l1), r(r1), s(s1), e(e1), line(line1) {}
};

struct LiChaoTree {
    vector<Node> nodes;

    LiChaoTree() { nodes.emplace_back(-1, -1, -INF, INF, Line()); }
    LiChaoTree(long long s, long long e) { nodes.emplace_back(-1, -1, s, e, Line()); }

    void update(int i, Line newLine) {
        long long s, e, mid;
        s = nodes[i].s; e = nodes[i].e;
        mid = (s + e) / 2;

        Line low, high;
        if (nodes[i].line.f(s) > newLine.f(s)) {
            low = newLine;
            high = nodes[i].line;
        } else {
            low = nodes[i].line;
            high = newLine;
        }

        if (low.f(e) < high.f(e)) {
            nodes[i].line = high;
        } else if (low.f(mid) < high.f(mid)) {
            nodes[i].line = high;
            if (nodes[i].r == -1) {
                nodes[i].r = nodes.size();
                nodes.emplace_back(-1, -1, mid + 1, e, Line());
            }
            update(nodes[i].r, low);
        } else {
            nodes[i].line = low;
            if (nodes[i].l == -1) {
                nodes[i].l = nodes.size();
                nodes.emplace_back(-1, -1, s, mid, Line());
            }
            update(nodes[i].l, high);
        }
    }

    long long query(int i, long long x) {
        if (i == -1) return -INF;
        long long mid = (nodes[i].s + nodes[i].e) / 2;
        long long ret = nodes[i].line.f(x);
        if (x <= mid) return max(ret, query(nodes[i].l, x));
        else return max(ret, query(nodes[i].r, x));
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    long long N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];

    // dp[i] = b[j] * a[i] + dp[j]
    vector<long long> dp(N);
    LiChaoTree tree(-1e9, 1e9);

    for(int i = 1; i < N; i++){
        // 새로운 직선을 스택에 push
        tree.update(0, Line(-b[i-1], -dp[i-1]));
        // dp 값 계산
        dp[i] = -tree.query(0, a[i]);
    }

    cout << dp[N - 1] << '\n';
}