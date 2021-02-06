#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 10000;
bool finished[MAX];
int dfsn[MAX];
int sn[MAX];
vector<int> adj[MAX];
vector<int> stack;
int cnt = 0, SN = 0;
vector<vector<int>> SCC;

int dfs(int curr) {
	cnt++;
	dfsn[curr] = cnt;
	stack.push_back(curr);

	int result = dfsn[curr];
	for (int next : adj[curr]) {
		if (dfsn[next] == 0) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	if (result == dfsn[curr]) {
		vector<int> currSCC;
		while (true) {
			int t = stack.back();
			stack.pop_back();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}

		sort(currSCC.begin(), currSCC.end());
		SCC.push_back(currSCC);
		SN++;
	}
	return result;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;
		adj[A - 1].push_back(B - 1);
	}

	for (int i = 0; i < V; i++) {
		if (dfsn[i] == 0) {
			dfs(i);
		}
	}

	sort(SCC.begin(), SCC.end());

	cout << SN << endl;

	for (vector<int>& currSCC : SCC) {
		for (int curr : currSCC)
			cout << curr+1 << ' ';
		cout << -1 << endl;
	}
}