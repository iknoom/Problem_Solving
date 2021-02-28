#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

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

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> M;

    for (int u = 0; u < N; u++) {
        int a;
        cin >> a;
        make_edge(SOURCE, u, a, 0);
    }
    for (int u = MAX_A; u < MAX_A + M; u++) {
        int b;
        cin >> b;
        make_edge(u, SINK, b, 0);
    }
    vector<vector<int>> C;
    for (int i = 0; i < M; i++) {
        vector<int> tmp;
        for (int j = 0; j < N; j++) {
            int cap;
            cin >> cap;
            tmp.push_back(cap);
        }
        C.push_back(tmp);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int cost;
            cin >> cost;
            make_edge(j, i + MAX_A, C[i][j], cost);
        }
    }

    mcmf();
    cout << ans_flow << '\n';
    cout << ans_cost << '\n';
}