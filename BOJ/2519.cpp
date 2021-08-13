#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int, int>;

const int MAX = 3000;
int dfsn[MAX * 2], finished[MAX * 2];
vector<int> adj[MAX * 2];
vector<int> st;

int dfs_cnt, scc_cnt;

int dfs(int u) {
    dfsn[u] = ++dfs_cnt;
    st.push_back(u);
    int ret = dfsn[u];
    for (auto v : adj[u]) {
        if (!dfsn[v]) ret = min(ret, dfs(v));
        else if (!finished[v]) ret = min(ret, dfsn[v]);
    }
    if (ret == dfsn[u]) {
        scc_cnt++;
        while (true) {
            int t = st.back();
            st.pop_back();
            finished[t] = scc_cnt;
            if (t == u) break;
        }
    }
    return ret;
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

bool conflict(ti a, ti b) {
    auto[ax1, ay1, ax2, ay2] = a;
    auto[bx1, by1, bx2, by2] = b;
    pi a1, a2, b1, b2;
    a1 = {ax1, ay1};
    a2 = {ax2, ay2};
    b1 = {bx1, by1};
    b2 = {bx2, by2};
    if (a1 > a2) swap(a1, a2);
    if (b1 > b2) swap(b1, b2);
    int p = ccw(a1, a2, b1) * ccw(a1, a2, b2);
    int q = ccw(b1, b2, a1) * ccw(b1, b2, a2);
    if (p == 0 && q == 0) {
        return !(a2 < b1 || b2 < a1);
    }
    return p <= 0 && q <= 0;
}

int main() {
    fastio;
    int N;
    cin >> N;
    vector<ti> lines;
    for (int i = 0; i < 3 * N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines.emplace_back(x1, y1, x2, y2);
    }
    for (int i = 0; i < 3 * N - 1; i++) {
        for (int j = i + 1; j < 3 * N; j++) {
            if (conflict(lines[i], lines[j])) {
                // !i | !j
                adj[i * 2].push_back(j * 2 + 1);
                adj[j * 2].push_back(i * 2 + 1);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int a = i * 3, b = i * 3 + 1, c = i * 3 + 2;
        // a | b
        adj[a * 2 + 1].push_back(b * 2);
        adj[b * 2 + 1].push_back(a * 2);
        // a | c
        adj[a * 2 + 1].push_back(c * 2);
        adj[c * 2 + 1].push_back(a * 2);
        // b | c
        adj[b * 2 + 1].push_back(c * 2);
        adj[c * 2 + 1].push_back(b * 2);
    }

    for (int i = 0; i < 3 * N * 2; i++) {
        if (!dfsn[i]) dfs(i);
    }
    vector<pi> tmp;
    for (int i = 0; i < 3 * N; i++) {
        if (finished[i * 2] == finished[i * 2 + 1]) {
            cout << -1 << '\n';
            return 0;
        }
        tmp.emplace_back(finished[i * 2], i * 2);
        tmp.emplace_back(finished[i * 2 + 1], i * 2 + 1);
    }
    sort(all(tmp), greater<>());
    vector<int> SAT(3 * N), answer;
    for (auto[_, i] : tmp) {
        if (SAT[i / 2]) continue;
        SAT[i / 2] = 1;
        if (i % 2 == 0) answer.push_back(i / 2 + 1);
    }
    cout << sz(answer) << '\n';
    for (auto k : answer) {
        cout << k << ' ';
    }
}