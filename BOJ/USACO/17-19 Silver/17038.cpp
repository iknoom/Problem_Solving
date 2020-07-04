#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using pi = pair<int, bool>;
const int MAX = 100000;

int N, M, vst[MAX];
vector<pi> adj[MAX];

bool dfs(int u) {
    for (auto p : adj[u]) {
        int v = p.first; bool is_same = p.second;
        if (!vst[v]) {
            if (is_same) vst[v] = vst[u];
            else vst[v] = 3 - vst[u];
            dfs(v);
        }
        else {
            if (is_same && vst[u] != vst[v]) return false;
            if (!is_same && vst[u] == vst[v]) return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        char c; bool d;
        int a, b;
        cin >> c >> a >> b;
        d = (c == 'S') ? true : false;
        adj[a - 1].push_back({ b - 1, d });
        adj[b - 1].push_back({ a - 1, d });
    }

    bool ans = true;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (!vst[i]) {
            cnt++;
            vst[i] = 1;
            ans = dfs(i);
        }
    }
    if (ans) {
        cout << 1;
        while (cnt--) cout << 0;
        cout << endl;
    }
    else cout << 0 << endl;
}