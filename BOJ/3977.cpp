#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

stack<int> st;
vector<int> adj[MAXN];
int dfsn[MAXN], dfsn_cnt = 0;
vector<vector<int> > scc;
int group[MAXN];

int dfs(int here)
{
    st.push(here);
    dfsn[here] = ++dfsn_cnt;

    int min_dfsn = dfsn[here];

    for(int there : adj[here]) {
        if(group[there] != -1) continue;

        if(!dfsn[there]) {  // not visited
            min_dfsn = min(min_dfsn, dfs(there));
        } else {  // visited
            min_dfsn = min(min_dfsn, dfsn[there]);
        }
    }

    // pop stack and grouping
    if(min_dfsn == dfsn[here]) {
        vector<int> temp;
        while(!st.empty()) {
            int node = st.top();  st.pop();
            temp.push_back(node);
            group[node] = scc.size();
            if(node == here) break;
        }
        scc.push_back(temp);
    }

    return min_dfsn;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        fill_n(group, n, -1);
        fill_n(dfsn, n, 0);
        dfsn_cnt = 0;
        scc.clear();
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) adj[i].clear();

        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++) {
            if(!dfsn[i]) dfs(i);
        }
        reverse(scc.begin(), scc.end());

        int ans = 0;
        vector<int> vst(scc.size(), 0);

        for (auto v : scc) {
            int scc_n = group[v.front()];
            if (!vst[scc_n]) ans++;
            vst[scc_n] = 1;
            for (auto a : v) {
                for (auto b : adj[a]) {
                    vst[group[b]] = 1;
                }
            }
        }
        if (ans > 1) cout << "Confused" << '\n' << '\n';
        else {
            sort(scc[0].begin(), scc[0].end());
            for (auto k : scc[0]) {
                cout << k << '\n';
            }
            cout << '\n';
        }
    }
}