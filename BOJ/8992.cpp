#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using line = tuple<int, int, int, int, int>;
const int MAX_V = 505;
const int MAX_A = 200;

enum {
    SOURCE = 501,
    SINK
};

struct edge{
    int to, cap, f, cost;
    edge *dual;
    edge(int to1, int cap1, int cost1): to(to1), cap(cap1), cost(cost1), f(0), dual(nullptr) {}
    edge(): edge(-1, 0, 0) {}
    int spare() { return cap - f; }
    void addFlow(int f1) {
        f += f1;
        dual->f -= f1;
    }
};

int ans_flow, ans_cost;
vector<edge*> adj[MAX_V];

void make_edge(int from, int to, int cap, int cost) {
    edge *e1 = new edge(to, cap, cost), *e2 = new edge(from, 0, -cost);
    e1->dual = e2;
    e2->dual = e1;
    adj[from].push_back(e1);
    adj[to].push_back(e2);
}

void mcmf() {
    while (true) {
        int prev[MAX_V], dist[MAX_V];
        bool in_queue[MAX_V] = {0};
        edge *path[MAX_V] = {0};
        fill(prev, prev+MAX_V, -1);
        fill(dist, dist+MAX_V, 1e9);

        queue<int> q;
        q.push(SOURCE);
        dist[SOURCE] = 0;
        in_queue[SOURCE] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            in_queue[u] = false;
            for(edge *e: adj[u]){
                int v = e->to;
                if(e->spare() > 0 && dist[v] > dist[u] + e->cost){
                    dist[v] = dist[u] + e->cost;
                    prev[v] = u;
                    path[v] = e;
                    if (!in_queue[v]) {
                        q.push(v);
                        in_queue[v] = true;
                    }
                }
            }
        }
        if(prev[SINK] == -1) break;

        int flow = 1e9;
        for(int i = SINK; i != SOURCE; i = prev[i]) {
            flow = min(flow, path[i]->spare());
        }
        for(int i = SINK; i != SOURCE; i = prev[i]) {
            ans_cost += path[i]->cost * flow;
            path[i]->addFlow(flow);
        }
        ans_flow += flow;
    }
}

void init() {
    ans_cost = 0;
    ans_flow = 0;
    for (int i = 0; i < MAX_V; i++) {
        adj[i].clear();
    }
}

void solution() {
    int n, m;
    cin >> n >> m;
    vector<line> h_lines, v_lines;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;
        if (x1 > x2) swap(x1, x2);
        h_lines.emplace_back(x1, y1, x2, y2, w);
        make_edge(SOURCE, i, 1, 0);
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;
        if (y1 > y2) swap(y1, y2);
        v_lines.emplace_back(x1, y1, x2, y2, w);
        make_edge(i + MAX_A, SINK, 1, 0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto [ax1, ay1, ax2, ay2, aw] = h_lines[i];
            auto [bx1, by1, bx2, by2, bw] = v_lines[j];
            if ((by1 < ay1) && (ay1 < by2) && (ax1 < bx1) && (bx1 < ax2)) {
                make_edge(i, j + MAX_A, 1, -aw * bw);
            }
        }
    }
    mcmf();
    cout << ans_flow << ' ' << -ans_cost << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        init();
        solution();
    }
}