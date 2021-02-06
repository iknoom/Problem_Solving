#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 205;
const int MAX_A = 100;
enum {
    SOURCE = 201,
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

int N, M, ans_flow, ans_cost;
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

int make_flow(int source, int sink) { // Edmonds-Karp
    int total = 0;
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
                if(e->spare() > 0 && prev[v] == -1){
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
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int A_i;
        cin >> A_i;
        make_edge(SOURCE, i, A_i, 0);
    }
    for (int i = 0; i < M; i++) {
        int B_i;
        cin >> B_i;
        make_edge(i + MAX_A, SINK, B_i, 0);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int C_ij;
            cin >> C_ij;
            make_edge(j, i + MAX_A, 1e9, C_ij);
        }
    }
    mcmf();
    cout << ans_cost << '\n';
}