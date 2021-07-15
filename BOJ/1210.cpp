#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int SOURCE = 403;
const int SINK = 404;
int n, m;

class Dinic {
    struct Edge {
        int v, rev;
        long long cap;
        Edge(int v, long long cap, int rev) : v(v), cap(cap), rev(rev) {}
    };

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
                long long cap = i.cap;
                if (level[there] == -1 && cap > 0) {
                    level[there] = level[here] + 1;
                    qu.push(there);
                }
            }
        }
        return level[E] != -1;
    }

    long long dfs(int here, long long crtcap) {
        if (here == E) return crtcap;
        for (int &i = work[here]; i < int(adj[here].size()); i++) {
            int there = adj[here][i].v;
            long long cap = adj[here][i].cap;
            if (level[here] + 1 == level[there] && cap > 0) {
                long long c = dfs(there, min(crtcap, cap));
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
    void add_edge(int s, int e, long long c) {
        adj[s].emplace_back(e, c, (int)adj[e].size());
        adj[e].emplace_back(s, 0, (int)adj[s].size() - 1);
    }

    long long get_max_flow(int s, int e) {
        S = s, E = e;
        long long res = 0;
        while (bfs()) {
            fill(work.begin(), work.end(), 0);
            while (1) {
                long long flow = dfs(S, INF);
                if (!flow) break;
                res += flow;
            }
        }
        return res;
    }

    vector<int> get_cut(int s) {
        vector<int> ret;
        vector<bool> vst(MAX_V, false);
        queue<int> q;
        q.push(s);
        vst[s] = true;
        while (!q.empty()) {
            int here = q.front();
            q.pop();
            for (auto i : adj[here]) {
                int there = i.v;
                long long cap = i.cap;
                if (!vst[there] && cap > 0) {
                    vst[there] = true;
                    q.push(there);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (vst[i * 2] && !vst[i * 2 + 1]) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};

int main() {
    fastio;
    Dinic dinic(405);
    cin >> n >> m;
    int s, e;
    cin >> s >> e;
    for (int i = 1; i <= n; i++) {
        long long c;
        cin >> c;
        dinic.add_edge(i * 2, i * 2 + 1, c);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dinic.add_edge(u * 2 + 1, v * 2, INF);
        dinic.add_edge(v * 2 + 1, u * 2, INF);
    }
    dinic.add_edge(SOURCE, s * 2, INF);
    dinic.add_edge(e * 2 + 1, SINK, INF);

    dinic.get_max_flow(SOURCE, SINK);

    vector<int> cut = dinic.get_cut(SOURCE);
    for (auto k : cut) {
        cout << k << ' ';
    }
    cout << '\n';
}