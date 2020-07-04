#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;
const int MAX = 5000;
int K, N, dfsn[MAX * 2 + 1], SCCn[MAX * 2 + 1], d_n, S_n;
int ans[MAX];
vector<int> adj[MAX * 2 + 1], stack;


int dfs(int u) {
	dfsn[u] = ++d_n;
	stack.push_back(u);
	int ret = dfsn[u];

	for (auto v : adj[u]) {
		if (!dfsn[v]) ret = min(ret, dfs(v));
		else if (!SCCn[v]) ret = min(ret, dfsn[v]);
	}

	if (ret == dfsn[u]) {
		S_n++;
		while (true) {
			int v = stack.back();
			stack.pop_back();
			SCCn[v] = S_n;
			if (v == u) break;
		}
	}

	return ret;
}

void get_sat() {
	vector<pi> v;
	for (int i = 1; i <= K; i++) {
		v.push_back({ SCCn[MAX + i], MAX + i });
		v.push_back({ SCCn[MAX - i], MAX - i });
	}
	sort(v.begin(), v.end(), greater<pi>());
	for (auto p : v) {
		int u = p.second;
		int rb;
		if (u > MAX) { u = u - MAX; rb = 2; }
		else { u = MAX - u; rb = 1; }
		
		if (!ans[u - 1]) ans[u - 1] = rb;
	}
}

int main()
{
	cin >> K >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c; char rb;
		cin >> a >> rb; if (rb == 'B') a = -a;
		cin >> b >> rb; if (rb == 'B') b = -b;
		cin >> c >> rb; if (rb == 'B') c = -c;
		adj[MAX - a].push_back(MAX + b); adj[MAX - a].push_back(MAX + c);
		adj[MAX - b].push_back(MAX + a); adj[MAX - b].push_back(MAX + c);
		adj[MAX - c].push_back(MAX + a); adj[MAX - c].push_back(MAX + b);
	}

	for (int i = 1; i <= K; i++) {
		if (!dfsn[MAX + i]) dfs(MAX + i);
		if (!dfsn[MAX - i]) dfs(MAX - i);
	}

	for (int i = 1; i <= K; i++) {
		if (SCCn[MAX + i] == SCCn[MAX - i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	get_sat();
	for (int i = 0; i < K; i++) {
		if (ans[i] == 1) cout << 'R';
		else cout << 'B';
	}
	cout << endl;
}
