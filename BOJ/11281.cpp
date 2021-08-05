#include <bits/stdc++.h>
#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;

const int MAX = 10000;
int N, M, dfsn[MAX * 2 + 1], finished[MAX * 2 + 1];
vector<int> adj[MAX * 2 + 1];
vector<int> st;

int dfs_cnt, scc_cnt;

int dfs(int u) {
	dfsn[u] = ++dfs_cnt;
	st.push_back(u);
	int ret = dfsn[u];
	for (auto v : adj[u]) {
		if (!dfsn[v]) ret = min(ret, dfs(v));
		else if (!finished[v]) ret = min(ret, dfsn[v]);
	}
	if (ret == dfsn[u]) {
		scc_cnt++;
		while (true) {
			int t = st.back();
			st.pop_back();
			finished[t] = scc_cnt;
			if (t == u) break;
		}
	}
	return ret;
}

int get_idx(int u) {
    if (u < 0) return (-u - 1) * 2 + 1;
    else return (u - 1) * 2;
}

int main() {
	fastio;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[get_idx(-a)].push_back(get_idx(b));
		adj[get_idx(-b)].push_back(get_idx(a));
	}

	for (int i = 0; i < N * 2; i++) {
		if (!dfsn[i]) dfs(i);
	}

	for (int i = 0; i < N; i++) {
		if (finished[i * 2] == finished[i * 2 + 1]) {
			cout << 0 << '\n';
			return 0;
		}
	}
	cout << 1 << '\n';
	vector<int> answer(N, -1);
	vector<pi> tmp(2 * N);
	for (int i = 0; i < N * 2; i++) {
	    tmp[i].x = finished[i];
	    tmp[i].y = i;
	}
	sort(all(tmp), greater<>());
	for (auto [_, i] : tmp) {
	    if (answer[i / 2] >= 0) continue;
        answer[i / 2] = i % 2;
	}

    for (auto k : answer) {
        cout << k << ' ';
    }
    cout << '\n';
}

