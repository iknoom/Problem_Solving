#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

const int val[6][6] = {
        {100, 70, 40, 0, 0, 0},
        {70, 50, 30, 0, 0, 0},
        {40, 30, 20, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
};

const int MAX_V = 2505;

enum {
    SOURCE = 2501,
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

int main() {
    fastio;
    int N;
    cin >> N;
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i + j) % 2 == 1) {
                int cur = i * N + j;
                make_edge(cur, SINK, 1, 0);
            } else {
                int cur = i * N + j;
                make_edge(SOURCE, cur, 1, 0);
                make_edge(cur, SINK, INF, 0);
                for (int k = 0; k < 4; k++) {
                    int ni = i + dy[k], nj = j + dx[k];
                    if ((ni < 0) || (ni >= N) || (nj < 0) || (nj >= N)) continue;
                    int nxt = ni * N + nj;
                    make_edge(cur, nxt, 1, -val[board[i][j] - 'A'][board[ni][nj] - 'A']);
                }
            }
        }
    }
    mcmf();
    cout << -ans_cost << '\n';
}