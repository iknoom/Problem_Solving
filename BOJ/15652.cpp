#include <iostream>
using namespace std;
int A[8];
int N, M;

void dfs(int s, int L) {
	A[L] = s;
	if (L == M - 1) {
		for (int i = 0; i < M; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	else {
		for (int i = s; i <= N; i++) {
			dfs(i, L + 1);
		}
	}
}

int main()
{
	cout.tie(0); ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		dfs(i, 0);
}