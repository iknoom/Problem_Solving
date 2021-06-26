#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
enum {
    SOURCE = 2500,
    SINK
};

class Dinic {
    struct Edge {
        int v, cap, rev;
        Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
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

    int get_max_flow() {
        S = SOURCE, E = SINK;
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

    int get_rest() {
        int ret = 0;
        for (Edge e : adj[SOURCE]) {
            ret += e.cap;
        }
        for (Edge e : adj[SINK]) {
            ret += adj[e.v][e.rev].cap;
        }
        return ret;
    }
};

vector<int> solution() {
    int n, m, board[50][50];
    cin >> n >> m;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> board[y][x];
        }
    }
    Dinic dinic(2502);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int cur = x + y * m;
            if ((x + y) % 2) {
                for (int i = 0; i < 4; i++) {
                    int x1 = x + dx[i], y1 = y + dy[i];
                    if (x1 < 0 || m <= x1) continue;
                    if (y1 < 0 || n <= y1) continue;
                    int nxt = x1 + y1 * m;
                    dinic.add_edge(cur, nxt, INF);
                }
                dinic.add_edge(SOURCE, cur, board[y][x]);
            } else {
                dinic.add_edge(cur, SINK, board[y][x]);
            }
        }
    }
    cout << dinic.get_max_flow() + dinic.get_rest() << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}