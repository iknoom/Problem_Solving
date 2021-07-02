#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, M, p[500000];

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

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    int answer = 0;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        if (!_union(u, v) && answer == 0) {
             answer = i;
        }
    }
    cout << answer << '\n';
}