#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
int N, row_sum[50], col_sum[50];
const int MAX1 = 2500;
const int MAX2 = 2550;
const int SOURCE = 2601;
const int SINK = 2602;

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

    void print_board(int max_cap) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int val, node = i * N + j;
                for (auto[e, c, _] : adj[node]) {
                    val = max_cap - c;
                }
                cout << val << ' ';
            }
            cout << '\n';
        }
    }
};

bool solve(int max_cap) {
    if (max_cap < 0) {
        return false;
    }
    Dinic dinic(3000);
    int all = 0;
    for (int i = 0; i < N; i++) {
        all += row_sum[i];
        dinic.add_edge(SOURCE, MAX1 + i, row_sum[i]);
        dinic.add_edge(MAX2 + i, SINK, col_sum[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int node = i * N + j;
            dinic.add_edge(MAX1 + i, node, max_cap);
            dinic.add_edge(node, MAX2 + j, max_cap);
        }
    }
    int answer = dinic.get_max_flow(SOURCE, SINK);
    return answer == all;
}

void print_answer(int max_cap) {
    Dinic dinic(3000);
    for (int i = 0; i < N; i++) {
        dinic.add_edge(SOURCE, MAX1 + i, row_sum[i]);
        dinic.add_edge(MAX2 + i, SINK, col_sum[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int node = i * N + j;
            dinic.add_edge(MAX1 + i, node, max_cap);
            dinic.add_edge(node, MAX2 + j, max_cap);
        }
    }
    dinic.get_max_flow(SOURCE, SINK);
    dinic.print_board(max_cap);
}

int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> row_sum[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> col_sum[i];
    }
    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (solve(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
    print_answer(r);
}