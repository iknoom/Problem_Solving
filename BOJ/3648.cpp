#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

const int MAX = 1000;
int N, M, dfsn[MAX * 2], finished[MAX * 2];
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

int get_idx(int u) {
    if (u < 0) {
        return (-u - 1) * 2 + 1;
    } else {
        return (u - 1) * 2;
    }
}

void solution() {
    fill(dfsn, dfsn + N * 2, 0);
    fill(finished, finished + N * 2, 0);
    for (int i = 0; i < N * 2; i++) adj[i].clear();
    st.clear();
    dfs_cnt = scc_cnt = 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[get_idx(-u)].push_back(get_idx(v));
        adj[get_idx(-v)].push_back(get_idx(u));
    }
    adj[get_idx(-1)].push_back(get_idx(1));

    for (int i = 0; i < N * 2; i++) {
        if (!dfsn[i]) {
            dfs(i);
        }
    }
    string answer = "yes";
    for (int i = 0; i < N; i++) {
        if (finished[i * 2] == finished[i * 2 + 1]) {
            answer = "no";
        }
    }
    cout << answer << '\n';
}

int main() {
    fastio;
    while (cin >> N >> M) {
        solution();
    }
}