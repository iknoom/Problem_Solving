#include <bits/stdc++.h>
#define x first
#define y second
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;

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
    pi p1, p2, p3, p4;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> p4.x >> p4.y;
    if (is_intersect(p1, p2, p3, p4)) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}