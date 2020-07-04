#include <iostream>
using namespace std;
bool vst[100];
int f[100][100];
int N;

int dfs(int u){
	int ret = 1;
	vst[u] = true;
	for (int v = 0; v < N; v++) {
		if(!vst[v] && f[u][v])
			ret += dfs(v);
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		f[v - 1][u - 1] = 1;
	}
	for (int i = 0; i < N; i++) {
		fill(vst, vst + N, false);
		if (dfs(i) == N) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}