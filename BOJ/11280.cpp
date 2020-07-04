#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000;
int N, M, dfsn[MAX * 2 + 1], finished[MAX * 2 + 1];
vector<int> adj[MAX * 2 + 1];
vector<int> stack;

int dfs_cnt, scc_cnt;

int dfs(int u) {
    dfsn[u] = ++dfs_cnt;
    stack.push_back(u);

    int ret = dfsn[u];
    for (auto v : adj[u]) {
        if (!dfsn[v]) ret = min(ret, dfs(v));
        else if (!finished[v]) ret = min(ret, dfsn[v]);
    }

    if (ret == dfsn[u]) {
        scc_cnt++;
        while (true) {
            int t = stack.back();
            stack.pop_back();
            finished[t] = scc_cnt;
            if (t == u) break;
        }
    }
    return ret;
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[MAX - a].push_back(MAX + b);
        adj[MAX - b].push_back(MAX + a);
    }

    for (int i = 1; i <= N; i++) {
        if (!dfsn[MAX + i]) dfs(MAX + i);
        if (!dfsn[MAX - i]) dfs(MAX - i);
    }

    for (int i = 1; i <= N; i++) {
        if (finished[MAX + i] == finished[MAX - i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}

