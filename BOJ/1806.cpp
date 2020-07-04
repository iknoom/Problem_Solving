#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 100001;
int N, SB;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> SB;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int i = 0, j = 0, sum = 0, ans = INF;

	while (true) {
		if (sum >= SB) {
			ans = min(ans, j - i);
			sum -= v[i];
			i += 1;
		}
		else if (j == N)
			break;
		else {
			sum += v[j];
			j += 1;
		}
	}
	cout << (ans == INF ? 0 : ans);
}