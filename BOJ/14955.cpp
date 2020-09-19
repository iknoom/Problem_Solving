#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 101;

struct edge{
    int to, c, f, w;
    edge *dual;
    edge(int to1, int c1, int w1): to(to1), c(c1), f(0), w(w1), dual(nullptr) {}
    edge(): edge(-1, 0, 0) {}
    int spare() { return c - f; }
    void addFlow(int f1) {
        f += f1;
        dual->f -= f1;
    }
};

int N, M, K;
vector<edge*> adj[MAX_V];

void make_edge(int from, int to, int cap, int weight) {
    edge *e1 = new edge(to, cap, weight), *e2 = new edge(from, 0, weight);
    e1->dual = e2;
    e2->dual = e1;
    adj[from].push_back(e1);
    adj[to].push_back(e2);
}

int make_flow(int source, int sink, int max_weight) {
    int total = 0;
    for (int u = 0; u < N; u++) {
        for (auto e : adj[u]) {
            e->f = 0;
        }
    }
    while (true) {
        int prev[MAX_V];
        edge *path[MAX_V] = {0};
        fill(prev, prev + MAX_V, -1);
        queue<int> q;
        q.push(source);
        while(!q.empty() && prev[sink] == -1){
            int u = q.front();
            q.pop();
            for(edge *e: adj[u]){
                int v = e->to;
                if(e->spare() > 0 && e->w < max_weight && prev[v] == -1){
                    q.push(v);
                    prev[v] = u;
                    path[v] = e;
                    if(v == sink) break;
                }
            }
        }
        if(prev[sink] == -1) break;
        int flow = 1e9;
        for(int i = sink; i != source; i = prev[i])
            flow = min(flow, path[i]->spare());
        for(int i = sink; i != source; i = prev[i])
            path[i]->addFlow(flow);
        total += flow;
    }
    return total;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        make_edge(v, u, 1, w);
        make_edge(u, v, 1, w);
    }
    int ans = 0;
    for (int u = 0; u < N; u++) {
        for (auto e : adj[u]) {
            if (e->c == 0) continue;
            int v = e->to;
            ans += make_flow(u, v, e->w);
        }
    }
    cout << ans/2 << '\n';
}