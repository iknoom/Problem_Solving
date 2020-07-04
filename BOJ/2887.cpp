#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int, int> tt;
int p[100000];

struct Edge {
	int u, v, w;
	bool operator <(const Edge& O) const {return w < O.w;}
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
	ios::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;

	vector<Edge> e;
	vector<vector<tt>> point(3);
	fill(p, p + N, -1);

	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		point[0].push_back(tt(x, i));
		point[1].push_back(tt(y, i));
		point[2].push_back(tt(z, i));
	}
	for (int i = 0; i < 3; i++)
		sort(point[i].begin(), point[i].end());

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < N - 1; i++) {
			int u = point[j][i].second;
			int v = point[j][i + 1].second;
			int w = point[j][i + 1].first - point[j][i].first;
			e.push_back({ u,v,w });
		}
	}
	sort(e.begin(), e.end());
	int ret = 0, cnt = 0;
	for (auto k : e) {
		if (merge(k.u, k.v)) {
			ret += k.w;
			cnt += 1;
		}
		if (cnt == N - 1) break;
	}

	cout << ret;
}