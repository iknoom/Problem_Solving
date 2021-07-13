#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ti = tuple<int, int, long long>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, M, p[2000];

int find(int u) {
    if (p[u] == u) return u;
    p[u] = find(p[u]);
    return p[u];
}

int main() {
    fastio;
    cin >> N >> M;

    vector<ti> edges;
    long long w = 1;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v, w);
        w = (w * 3) % MOD;
    }

    reverse(all(edges));
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    long long answer = 0;
    for (auto[u, v, w] : edges) {
        int x = find(u);
        int y = find(v);
        int a = find(0);
        int b = find(N - 1);
        if ((a == x && b == y) || (a == y && b == x)) {
            answer += w;
        } else {
            p[x] = y;
        }
    }
    cout << answer % MOD << '\n';
}