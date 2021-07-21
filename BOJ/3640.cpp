#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
const int MAX_V = 2005;

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

int N, M, ans_flow, ans_cost, SOURCE, SINK;
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
        vector<int> prev(N * 2 + 2, -1), dist(N * 2 + 2, 1e9);
        vector<bool> in_queue(N * 2 + 2, false);
        vector<edge*> path(N * 2 + 2);
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
        if (ans_flow == 2) {
            break;
        }
    }
}

void solution() {
    ans_flow = 0;
    ans_cost = 0;
    for (int i = 0; i < N * 2 + 3; i++) {
        adj[i].clear();
    }
    SOURCE = N * 2; SINK = N * 2 + 1;
    make_edge(SOURCE, 0, 2, 0);
    make_edge((N - 1) * 2 + 1, SINK, 2, 0);
    make_edge(0, 1, 2, 0);
    make_edge((N - 1) * 2, (N - 1) * 2 + 1, 2, 0);
    for (int i = 1; i < N - 1; i++) {
        make_edge(i * 2, i * 2 + 1, 1, 0);
    }
    while (M--) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--; v--;
        make_edge(u * 2 + 1, v * 2, 1, cost);
    }
    mcmf();
    cout << ans_cost << '\n';
}

int main() {
    fastio;
    while (cin >> N >> M) {
        solution();
    }
}