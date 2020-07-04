#include <iostream>
using namespace std;
int V[10001], L[10001], R[10001];

void _insert(int u) {
	if (u == 1) return;
	int p = 1;
	while (true) {
		if (V[u] < V[p]) {
			if (!L[p]) {
				L[p] = u;
				return;
			}
			else p = L[p];
		}
		else {
			if (!R[p]) {
				R[p] = u;
				return;
			}
			else
				p = R[p];
		}
	}
}

void dfs(int u) {
	if (L[u]) dfs(L[u]);
	if (R[u]) dfs(R[u]);
	cout << V[u] << endl;
}

int main()
{

	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	for (int i = 1, input; cin >> input; i++) {
		V[i] = input;
		_insert(i);
	}
	dfs(1);
}