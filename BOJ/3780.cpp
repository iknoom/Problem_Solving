#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

pi find(int v, vector<pi> &p) {
    if (p[v].first == v) return {v, 0};
    auto[nxt_p, d] = find(p[v].first, p);
    p[v].first = nxt_p;
    p[v].second += d;
    return p[v];
}

void merge(int u, int v, vector<pi> &p) {
    p[u].first = v;
    p[u].second = abs(u - v) % 1000;
}

void solution() {
    int N;
    cin >> N;
    vector<pi> p(N);
    for (int i = 0; i < N; i++) {
        p[i].first = i;
        p[i].second = 0;
    }
    while (true) {
        char c;
        cin >> c;
        if (c == 'O') {
            break;
        }
        if (c == 'I') {
            int I, J;
            cin >> I >> J;
            I--; J--;
            merge(I, J, p);
        } else if (c == 'E') {
            int I;
            cin >> I;
            I--;
            auto[Ip, dist] = find(I, p);
            cout << dist << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}