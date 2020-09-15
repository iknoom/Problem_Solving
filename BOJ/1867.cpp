#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 501;
int n, k, A[MAX_SIZE], B[MAX_SIZE];
vector<int> adj[MAX_SIZE];
bool vst[MAX_SIZE];

bool dfs(int u) {
    vst[u] = true;
    for (auto v : adj[u]) {
        if (B[v] < 0 || (!vst[B[v]] && dfs(B[v]))) {
            A[u] = v;
            B[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        adj[r - 1].push_back(c - 1);
    }
    fill(A, A + n, -1);
    fill(B, B + n, -1);
    int ans = 0;
    for (int u = 0; u < n; u++) {
        if (A[u] < 0) {
            memset(vst, 0, sizeof(vst));
            if (dfs(u)) ans++;
        }
    }
    cout << ans << '\n';
}