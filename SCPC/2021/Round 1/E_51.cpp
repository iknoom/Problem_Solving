#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int N, K;

int find(int u, vector<int> &p) {
    if (p[u] == u) return u;
    p[u] = find(p[u], p);
    return p[u];
}

void solution() {
    // uf
    vector<int> p(N + 1);
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }
    while (K--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, d;
            cin >> l >> r >> d;
            l = find(l, p);
            r = find(r, p);
            p[l] = r;
        } else {
            int l, r;
            cin >> l >> r;
            if (find(l, p) == find(r, p)) {
                cout << 0 << '\n';
            } else {
                cout << "NC" << '\n';
            }
        }
    }
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> N >> K;
        cout << "Case #" << i << '\n';
        solution();
    }
}