#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;
int N;
const int MAX = 40001;
const int MAX_D = 16;
vector<pi> adj[MAX];
int depth[MAX];
int dist[MAX];
int p[MAX][MAX_D + 1];


void DFS(int u, int d, int D) {
	for (auto vw : adj[u]) {
		int v, w;
		tie(v, w) = vw;
		if (!depth[v]) {
			depth[v] = d + 1;
			dist[v] = D + w;
			p[v][0] = u;
			DFS(v, d + 1, D + w);
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	int diff = depth[v] - depth[u];
	for (int j = 0; j <= MAX_D; j++) {
		if (diff & 1) v = p[v][j];
		diff >>= 1;
	}
	if (u == v) return u;
	for (int j = MAX_D; j >= 0; j--) {
		if (p[u][j] != p[v][j]) {
			u = p[u][j];
			v = p[v][j];
		}
	}
	return p[u][0];
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	depth[1] = 1;
	DFS(1, 1, 0);

	for (int j = 1; j <= MAX_D; j++) {
		for (int i = 1; i <= N; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int u, v, x;
		cin >> u >> v;
		x = LCA(u, v);
		cout << dist[u] + dist[v] - 2 * dist[x] << '\n';
	}
}

