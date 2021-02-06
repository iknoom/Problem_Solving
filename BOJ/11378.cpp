#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
enum {
    SOURCE = 2001,
    MID,
    SINK
};

class Dinic {
    // 간선 구조체, 반대쪽에 연결된 정점과 용량 역방향 간선의 위치를 가지고 있다.
    struct Edge {
        int v, cap, rev;
        Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
    };

    int MAX_V;
    int S, E;  // source, sink
    vector<vector<Edge>> adj;
    vector<int> level, work;

    bool bfs() {
        fill(level.begin(), level.end(), -1);  // 레벨 그래프 초기화
        queue<int> qu;
        level[S] = 0;
        qu.push(S);
        while (qu.size()){
            int here = qu.front();
            qu.pop();
            for (auto i : adj[here]) {
                int there = i.v;
                int cap = i.cap;
                if (level[there] == -1 && cap > 0) {  // 레벨이 아직 정해지지 않았고 잔여용량이 0 이상
                    level[there] = level[here] + 1;  // 현재의 레벨값+1을 할당해준다.
                    qu.push(there);
                }
            }
        }
        return level[E] != -1;  // 싱크의 레벨이 할당이 안된 경우 0을 리턴
    }

    int dfs(int here, int crtcap) {
        if (here == E) return crtcap;  // 싱크일 경우 현재 흐르는 유량을 return
        for (int &i = work[here]; i < int(adj[here].size()); i++) {  // work 배열에는 다음 탐색 위치가 저장되어 있다.
            int there = adj[here][i].v;
            int cap = adj[here][i].cap;
            if (level[here] + 1 == level[there] && cap > 0) {  // 레벨 그래프가 1만큼 크고 잔여 용량이 0 이상인 간선
                int c = dfs(there, min(crtcap, cap));  // dfs로 다음 위치 탐색
                if (c > 0) {  // 싱크까지 도달하여 흐르는 차단유량이 0 이상일 경우
                    adj[here][i].cap -= c;  // 현재 용량에서 차단 유량만큼을 빼줌
                    adj[there][adj[here][i].rev].cap += c;  // 역방향 간선에 c만큼 용량을 추가해줌
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

    // 벡터의 사이즈 만큼을 넣어주어 역방향 간선의 위치를 저장한다.
    void add_edge(int s, int e, int c) {
        adj[s].emplace_back(e, c, (int)adj[e].size());
        adj[e].emplace_back(s, 0, (int)adj[s].size() - 1);
    }

    int get_max_flow(int s, int e) {
        S = s, E = e;
        int res = 0;
        while (bfs()) {  // 레벨 그래프가 만들어 지는 경우에만 동작
            fill(work.begin(), work.end(), 0);
            while (1) {
                int flow = dfs(S, INF);  // 차단유량을 구하여
                if (!flow) break;
                res += flow;  // 차단 유량이 1 이상일 경우 maximum flow에 더해줌
            }
        }
        return res;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    Dinic DN = Dinic(2005);
    DN.add_edge(SOURCE, MID, K);
    for (int i = 0; i < N; i++) {
        DN.add_edge(SOURCE, i, 1);
        DN.add_edge(MID, i, INF);
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int to;
            cin >> to;
            to--;
            DN.add_edge(i, 1000 + to, 1);
        }
    }
    for (int i = 0; i < M; i++) {
        DN.add_edge(1000 + i, SINK, 1);
    }

    cout << DN.get_max_flow(SOURCE, SINK);
}
