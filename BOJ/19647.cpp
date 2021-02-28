#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MAX = 1000;
int N, A[MAX], B[MAX];
vector<int> adj[MAX];
vector<int> adj_inv[MAX];
bool vst[MAX];

bool dfs(int u) {
    vst[u] = true;
    for (auto v : adj[u]) {
        if (B[v] == -1 || !vst[B[v]] && dfs(B[v])) {
            A[u] = v;
            B[v] = u;
            return true;
        }
    }
    return false;
}

bool bfs(int s) {
    vector<bool> vst2(N);
    queue<int> q;
    vst2[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj_inv[A[u]]) {
            if (v == u) continue;
            if (v == s) return true;
            if (vst2[v]) continue;
            vst2[v] = true;
            q.push(v);
        }
    }
    return false;
}

int main() {
    fastio;
    // input
    cin >> N;
    for (int u = 0; u < N; u++) {
        int T;
        cin >> T;
        while (T--) {
            int v;
            cin >> v;
            v--;
            adj_inv[v].push_back(u);
            adj[u].push_back(v);
        }
    }
    // matching
    fill(A, A + N, -1);
    fill(B, B + N, -1);
    for (int u = 0; u < N; u++) {
        fill(vst, vst + N, false);
        if (!dfs(u)) {
            cout << -1 << '\n';
            return 0;
        }
    }
    // is cycle
    for (int u = 0; u < N; u++) {
        if (bfs(u)) {
            cout << -1 << '\n';
            return 0;
        }
    }
    // print answer
    cout << 1 << '\n';
    for (int i = 0; i < N; i++) {
        cout << A[i] + 1 << ' ';
    }
    cout << '\n';
}