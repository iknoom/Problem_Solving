#include <bits/stdc++.h>
#define x first
#define y second
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
int N, p[3000];

int _find(int u) {
    if (p[u] == u) {
        return u;
    }
    p[u] = _find(p[u]);
    return p[u];
}

bool _union(int u, int v) {
    u = _find(u);
    v = _find(v);
    if (u == v) {
        return false;
    }
    p[u] = v;
    return true;
}

int ccw(pi A, pi B, pi C) {
    long long op = (long long)A.x * B.y
                   + (long long)B.x * C.y
                   + (long long)C.x * A.y;
    op -= (long long)A.x * C.y
          + (long long)B.x * A.y
          + (long long)C.x * B.y;
    if (op > 0) return 1;
    if (op < 0) return -1;
    else return 0;
}

bool is_intersect(pi a1, pi b1, pi a2, pi b2) {
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    int p = ccw(a1, b1, a2) * ccw(a1, b1, b2);
    int q = ccw(a2, b2, a1) * ccw(a2, b2, b1);
    if (p == 0 && q == 0) {
        return !(b1 < a2 || b2 < a1);
    }
    return p <= 0 && q <= 0;
}

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    vector<pi> point1(N), point2(N);
    for (int i = 0; i < N; i++) {
        cin >> point1[i].x >> point1[i].y >> point2[i].x >> point2[i].y;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (is_intersect(point1[i], point2[i], point1[j], point2[j])) {
                _union(i, j);
            }
        }
    }
    map<int, int> S;
    for (int i = 0; i < N; i++) {
        S[_find(i)] += 1;
    }
    cout << S.size() << '\n';
    int answer = -1;
    for (auto[_, value] : S) {
        answer = max(answer, value);
    }
    cout << answer << '\n';
}