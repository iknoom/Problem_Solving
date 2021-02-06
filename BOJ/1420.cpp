#include <bits/stdc++.h>

using namespace std;

class Dinic {
    struct Edge {
        int v, cap, rev;
        Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
    };

    const int INF = 987654321;
    int MAX_V;
    int S, E;  // source, sink
    vector<vector<Edge>> adj;
    vector<int> level, work;

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> qu;
        level[S] = 0;
        qu.push(S);
        while (qu.size()){
            int here = qu.front();
            qu.pop();
            for (auto i : adj[here]) {
                int there = i.v;
                int cap = i.cap;
                if (level[there] == -1 && cap > 0) {
                    level[there] = level[here] + 1;
                    qu.push(there);
                }
            }
        }
        return level[E] != -1;
    }

    int dfs(int here, int crtcap) {
        if (here == E) return crtcap;
        for (int &i = work[here]; i < int(adj[here].size()); i++) {
            int there = adj[here][i].v;
            int cap = adj[here][i].cap;
            if (level[here] + 1 == level[there] && cap > 0) {
                int c = dfs(there, min(crtcap, cap));
                if (c > 0) {
                    adj[here][i].cap -= c;
                    adj[there][adj[here][i].rev].cap += c;
                    return c;
                }
            }
        }
        return 0;
    }

public:
    Dinic(int MAX_V) : MAX_V(MAX_V) {
        adj.resize(MAX_V);
        level.resize(MAX_V);
        work.resize(MAX_V);
    }

    void add_edge(int s, int e, int c) {
        adj[s].emplace_back(e, c, (int)adj[e].size());
        adj[e].emplace_back(s, 0, (int)adj[s].size() - 1);
    }

    int get_max_flow(int s, int e) {
        S = s, E = e;
        int res = 0;
        while (bfs()) {
            fill(work.begin(), work.end(), 0);
            while (1) {
                int flow = dfs(S, INF);
                if (!flow) break;
                res += flow;
            }
        }
        return res;
    }
};
int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, source, sink;
    cin >> N >> M;
    Dinic graph = Dinic(N * M * 2);
    vector<string> city;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        city.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (city[i][j] == '#') continue;
            int u, v, w;
            u = i * M + j;
            v = i * M + j + 1;
            w = (i + 1) * M + j;
            graph.add_edge(u * 2, u * 2 + 1, 1);
            if (city[i][j] == 'K') source = u * 2 + 1;
            if (city[i][j] == 'H') sink = u * 2;
            if (j < M - 1 && city[i][j + 1] != '#') {
                graph.add_edge(u * 2 + 1, v * 2, 1e9);
                graph.add_edge(v * 2 + 1, u * 2, 1e9);
            }
            if (i < N - 1 && city[i + 1][j] != '#') {
                graph.add_edge(u * 2 + 1, w * 2, 1e9);
                graph.add_edge(w * 2 + 1, u * 2, 1e9);
            }
        }
    }
    int ret = graph.get_max_flow(source, sink);
    if (ret >= 1e9) cout << -1 << endl;
    else cout << ret << endl;
}