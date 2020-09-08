#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 2005;
const int MAX_A = 1000;
enum {
    SOURCE = 2001,
    SINK,
    MID
};

struct edge{
    int to, cap, f;
    edge *dual;
    edge(int to1, int c1): to(to1), cap(c1), f(0), dual(nullptr) {}
    edge(): edge(-1, 0) {}
    int spare() { return cap - f; }
    void addFlow(int f1) {
        f += f1;
        dual->f -= f1;
    }
};

int N, M, K;
vector<edge*> adj[MAX_V];

void make_edge(int from, int to, int cap) {
    edge *e1 = new edge(to, cap), *e2 = new edge(from, 0);
    e1->dual = e2;
    e2->dual = e1;
    adj[from].push_back(e1);
    adj[to].push_back(e2);
}

int make_flow() {
    int total = 0;
    while (true) {
        int prev[MAX_V];
        edge *path[MAX_V] = {0};
        fill(prev, prev+MAX_V, -1);
        queue<int> q;
        q.push(SOURCE);
        while(!q.empty() && prev[SINK] == -1){
            int u = q.front();
            q.pop();
            for(edge *e: adj[u]){
                int v = e->to;
                if(e->spare() > 0 && prev[v] == -1){
                    q.push(v);
                    prev[v] = u;
                    path[v] = e;
                    if(v == SINK) break;
                }
            }
        }
        if(prev[SINK] == -1) break;
        int flow = 1e9;
        for(int i = SINK; i != SOURCE; i = prev[i])
            flow = min(flow, path[i]->spare());
        for(int i = SINK; i != SOURCE; i = prev[i])
            path[i]->addFlow(flow);
        total += flow;

    }
    return total;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;

    make_edge(SOURCE, MID, K);
    for (int u = 0; u < N; u++) {
        make_edge(SOURCE, u, 1);
        make_edge(MID, u, 1);
    }
    for (int u = 0; u < N; u++) {
        int s; cin >> s;
        while (s--) {
            int v; cin >> v;
            v--; v += MAX_A;
            make_edge(u, v, 1);
        }
    }
    for (int u = MAX_A; u < MAX_A + M; u++) {
        make_edge(u, SINK, 1);
    }

    cout << make_flow() << '\n';
}