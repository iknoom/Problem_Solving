#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;

stack<int> st;
vector<int> adj[MAXN];
int dfsn[MAXN], dfsn_cnt = 0;
vector<vector<int>> scc;
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
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    S--; T--;
    fill_n(group, N, -1);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    for(int i = 0; i < N; i++) {
        if(!dfsn[i]) dfs(i);
    }
    vector<int> dp(scc.size());
    vector<int> vst(scc.size(), 0);
    vector<int> vst2(scc.size(), 0);
    vector<int> indegree(scc.size(), 0);
    // fill indegree
    for (int i = group[S]; i >= 0; i--) {
        if (vst[i]) continue;
        vst[i] = 1;
        for (auto a : scc[i]) {
            for (auto b : adj[a]) {
                if (group[b] == group[a]) continue;
                indegree[group[b]]++;
            }
        }
    }
    // ts
    queue<int> q;
    q.push(group[S]);
    vst2[group[S]] = 1;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        dp[i] += scc[i].size();
        for (auto a : scc[i]) {
            for (auto b : adj[a]) {
                if (group[a] == group[b]) continue;
                if (vst2[group[b]]) continue;
                dp[group[b]] = max(dp[group[b]], dp[i]);
                indegree[group[b]]--;
                if (indegree[group[b]] == 0) {
                    q.push(group[b]);
                    vst2[group[b]] = 1;
                }
            }
        }
    }
    cout << dp[group[T]] << '\n';
}