#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K, M;
const int MAX = 31;
int next_K[100001][MAX];

int get_sol(int u, int n) {
	for (int j = MAX - 1; j >= 0; j--) {
		if (n >= (1 << j)) {
			u = next_K[u][j];
			n -= (1 << j);
		}
	}
	return u;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> N >> K >> M;
	vector<int> ans(N);
	for (int i = 0; i < N; i++) cin >> ans[i];
	for (int i = 1; i <= K; i++) cin >> next_K[i][0];

	for (int j = 1; j < MAX; j++) {
		for (int i = 1; i <= K; i++) {
			next_K[i][j] = next_K[ next_K[i][j - 1] ][j - 1];
		}
	}
	for (auto u : ans) {
		cout << get_sol(u, M - 1) << " ";
	}
}