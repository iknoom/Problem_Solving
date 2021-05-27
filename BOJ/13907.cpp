#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ti = tuple<int, int, long long>;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N, M, K, S, D;
long long min_dist[1000], all_inc;
vector<ti> edges;

long long get_fee() {
    long long ret = INF;
    for (long long i = 1; i <= N - 1; i++) {
        ret = min(ret, min_dist[i] + all_inc * i);
    }
    return ret;
}

void BellmanFord() {
    vector<long long> dist(N, INF);
    dist[S] = 0;
    for (int loop = 1; loop <= N - 1; loop++){
        vector<long long> next_dist(N);
        for (int i = 0; i < N; i++) {
            next_dist[i] = dist[i];
        }
        for (auto [u, v, t] : edges) {
            next_dist[v] = min(next_dist[v], dist[u] + t);
        }
        for (int i = 0; i < N; i++) {
            dist[i] = next_dist[i];
        }
        min_dist[loop] = dist[D];
    }
}

int main() {
    fastio;
    cin >> N >> M >> K;
    cin >> S >> D;
    S--; D--;
    for (int i = 0; i < M; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(u, v, w);
        edges.emplace_back(v, u, w);
    }
    // bellmanford
    BellmanFord();

    cout << get_fee() << '\n';

    for (int i = 0; i < K; i++) {
        int inc;
        cin >> inc;
        all_inc += inc;
        // get answer
        cout << get_fee() << '\n';
    }
}