#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
vector<int> v;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	int i = 0, j = 0, ans = 2000000001;

	while (true) {
		if (j == N)
			break;
		else if (i == j || v[j] - v[i] < M)
			j += 1;
		else  {
			ans = min(ans, v[j] - v[i]);
			i += 1;
		}
	}
	cout << ans;
}