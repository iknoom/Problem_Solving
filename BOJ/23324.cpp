#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
int p[200000];

int find(int u) {
    if (p[u] == u) return u;
    p[u] = find(p[u]);
    return p[u];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        p[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    K--;
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    int a, b;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (i == K) {
            a = u; b = v;
        } else {
            merge(u, v);
        }
    }
    if (find(a) == find(b)) {
        cout << 0 << '\n';
    } else {
        long long x = 0, y = 0;
        for (int i = 0; i < N; i++) {
            if (find(a) == find(i)) x++;
            if (find(b) == find(i)) y++;
        }
        cout << x * y << '\n';
    }
}