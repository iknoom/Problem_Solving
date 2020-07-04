#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;
using pi = pair<int, int>;

int N, Q;
int USADO[5000][5000];
vector<pi> adj[5000];

void dfs(int s, int u, int k) {
	for (auto t : adj[u]) {
		int v, k1;
		v = t.first;
		k1 = min(k, t.second);
		if (!USADO[s][v]) {
			USADO[s][v] = k1;
			dfs(s, v, k1);
		}
	}
}

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		adj[p - 1].push_back({ q - 1, r });
		adj[q - 1].push_back({ p - 1, r });
	}
	for (int i = 0; i < N; i++) {
		USADO[i][i] = -1;
		dfs(i, i, 1e9);
	}
	while (Q--) {
		int K, u, ret;
		cin >> K >> u;
		ret = 0;
		for (int i = 0; i < N; i++) {
			if (USADO[u - 1][i] >= K) {
				ret++;
			}
		}
		cout << ret << '\n';
	}
}

