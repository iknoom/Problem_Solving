#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int T, N;
int adj[10001];

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		fill(adj, adj + N + 1, 0);
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			adj[b] = a;
		}
		int a, b;
		cin >> a >> b;
		while (adj[a]) {
			int tmp = a;
			a = adj[a];
			adj[tmp] = -1;
		}
		adj[a] = -1;
		while (true) {
			if (adj[b] == -1) {
				cout << b << endl;
				break;
			}
			b = adj[b];
		}
	}


}