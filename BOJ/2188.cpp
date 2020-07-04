#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, A[200], B[200];
bool vst[200];
vector<int> adj[200];

bool dfs(int u) {
	vst[u] = true;
	for (auto v : adj[u]) {
		if (B[v] < 0 || !vst[B[v]] && dfs(B[v])) {
			A[u] = v;
			B[v] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int T;
		cin >> T;
		while (T--) {
			int j;
			cin >> j;
			adj[i].push_back(j - 1);
		}
	}

	int ans = 0;

	fill(A, A + N, -1);
	fill(B, B + M, -1);
	for (int u = 0; u < N; u++) {
		fill(vst, vst + N, false);
		if (dfs(u)) ans++;
	}
	cout << ans << endl;
}