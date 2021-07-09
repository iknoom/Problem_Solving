#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

class Dinic {
    struct Edge {
        int v, rev;
        long long cap;
        Edge(int v, long long cap, int rev) : v(v), cap(cap), rev(rev) {}
    };

    const long long INF = 1e18;
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
};

int N, M, val[26];
string board[50];
const int SOURCE = 5002;
const int SINK = 5003;
const long long CAP_MAX = 2e9;
const long long INF = 1e18;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    fastio;
    Dinic dinic(5005);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < 26; i++) {
        cin >> val[i];
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (board[y][x] == '-') continue;
            if (board[y][x] == '*') continue;
            int left_node = (y * M + x) * 2, right_node = (y * M + x) * 2 + 1;
            long long node_val = val[board[y][x] - 'A'] + CAP_MAX;
            // self to self
            dinic.add_edge(left_node, right_node, node_val);
            // sink to self
            if (x == 0 || y == 0 || x == M - 1 || y == N - 1) {
                dinic.add_edge(SOURCE, left_node, INF);
            }
            // self to next
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= M) continue;
                if (ny < 0 || ny >= N) continue;
                if (board[ny][nx] == '-') continue;
                if (board[ny][nx] == '*') {
                    dinic.add_edge(right_node, SINK, INF);
                } else {
                    int next_node = (ny * M + nx) * 2;
                    dinic.add_edge(right_node, next_node, INF);
                }
            }
        }
    }
    cout << dinic.get_max_flow(SOURCE, SINK) % CAP_MAX << '\n';
}