#include <iostream>
#include <vector>
using namespace std;
int N, M;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	vector<int> v;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	int i=0, j=0, S=0, ans=0;

	while (true) {
		if (S >= M) {
			S -= v[i];
			i += 1;
		}
		else if (j == N)
			break;
		else {
			S += v[j];
			j += 1;
		}

		if (S == M) ans += 1;
	}

	cout << ans;
}