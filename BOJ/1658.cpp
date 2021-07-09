#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;

class Dinic {
    struct Edge {
        int v, cap, rev;
        Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
    };

    const int INF = 2e9;
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

int M, N;
const int MAX = 1000;
const int SOURCE = 1100;
const int SINK = 1101;
const int INF = 1e9;
set<int> adj[100];

int main() {
    fastio;
    Dinic dinic(1102);
    cin >> M >> N;
    // to sink
    for (int i = 0; i < M; i++) {
        int v;
        cin >> v;
        dinic.add_edge(i, SINK, v);
    }
    // from source, 손님 -> 돼지
    for (int i = 0; i < N; i++) {
        int S;
        cin >> S;
        while (S--) {
            int j;
            cin >> j;
            j--;
            dinic.add_edge(i + MAX, j, INF);
            adj[i].insert(j);
        }
        int v;
        cin >> v;
        dinic.add_edge(SOURCE, i + MAX, v);
    }
    // check intersection
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            vector<int> tmp;
            set_intersection(all(adj[i]), all(adj[j]), back_inserter(tmp));
            if (!tmp.empty()) {
                dinic.add_edge(i + MAX, j + MAX, INF);
            }
        }
    }
    cout << dinic.get_max_flow(SOURCE, SINK) << '\n';
}