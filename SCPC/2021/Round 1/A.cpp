#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

void solution() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N, vector<int>());
    for (int u = 0; u < N; u++) {
        int d;
        cin >> d;
        int v = u + d;
        if (v < N){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int ret = 0;
    vector<bool> vst(N);
    for (int s = 0; s < N; s++) {
        if (vst[s]) continue;
        ret++;
        queue<int> q;
        q.push(s);
        vst[s] = true;
        // bfs
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (vst[v]) continue;
                vst[v] = true;
                q.push(v);
            }
        }
    }
    cout << ret << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << '\n';
        solution();
    }
}