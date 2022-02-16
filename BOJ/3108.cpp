#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
int p[1000];

struct rec {
    int x1, y1, x2, y2;
} recs[1000];

bool is_intersect(rec &a, rec &b) {
    if (a.x2 < b.x1 || b.x2 < a.x1) return false;
    if (a.y2 < b.y1 || b.y2 < a.y1) return false;
    if (a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && b.y2 < a.y2) return false;
    if (b.x1 < a.x1 && a.x2 < b.x2 && b.y1 < a.y1 && a.y2 < b.y2) return false;
    return true;
}

bool include_origin(rec &a) {
    if (a.y1 == 0 || a.y2 == 0) {
        if (a.x1 <= 0 && 0 <= a.x2) return true;
    }
    if (a.x1 == 0 || a.x2 == 0) {
        if (a.y1 <= 0 && 0 <= a.y2) return true;
    }
    return false;
}

int find(int u) {
    if (p[u] == u) return u;
    p[u] = find(p[u]);
    return p[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    p[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> recs[i].x1 >> recs[i].y1 >> recs[i].x2 >> recs[i].y2;
        p[i] = i;
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (is_intersect(recs[i], recs[j])) {
                merge(i, j);
            }
        }
    }
    set<int> S;
    int is_include_origin = 0;
    for (int i = 0; i < N; i++) {
        S.insert(find(i));
        if (include_origin(recs[i])) {
            is_include_origin = 1;
        }
    }
    cout << S.size() - is_include_origin << '\n';
}