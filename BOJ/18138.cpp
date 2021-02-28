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
const int MAX = 200;
int N, M, A[MAX], B[MAX];
vector<int> adj[MAX];
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

int main() {
    fastio;
    cin >> N >> M;
    vector<int> shirts, kara;
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        shirts.push_back(v);
    }
    for (int i = 0; i < M; i++) {
        int v;
        cin >> v;
        kara.push_back(v);
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        int w = shirts[i];
        int k = kara[j];
        if (w <= k * 2 && 4 * k <= 3 * w) {
            adj[i].push_back(j);
        } else if (w <= k && 4 * k <= 5 * w) {
            adj[i].push_back(j);
        }
    }

    int ans = 0;
    fill(A, A + N, -1);
    fill(B, B + N, -1);
    for (int u = 0; u < N; u++) {
        fill(vst, vst + N, false);
        if (dfs(u)) {
            ans++;
        }
    }
    cout << ans << '\n';
}