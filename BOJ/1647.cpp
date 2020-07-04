#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[100000];

struct Edge{
	int u, v, w;
	Edge(): Edge(0, 0, 0) {}
	Edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}
	bool operator <(Edge& O) {
		return w < O.w;
	}
};

int find(int u) {
	if (p[u] < 0) return u;
	return p[u] = find(p[u]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if (p[u] < p[v]) p[u] += p[v], p[v] = u;
	else p[v] += p[u], p[u] = v;
	return true;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	
	vector<Edge> e(M);
	fill(p, p+N, -1);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = Edge(u - 1, v - 1, w);
	}
	sort(e.begin(), e.end());

	int cnt = 1, ret = 0;
	for (auto cur : e) {
		if (merge(cur.u, cur.v)) {
			ret += cur.w;
			cnt += 1;
		}
		if (cnt == N - 1)
			break;
	}

	cout << ret << '\n';
}