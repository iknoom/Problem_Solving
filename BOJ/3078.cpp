#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, K;
	long long ans = 0;
	queue<int> q[21];
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string friend_name;
		cin >> friend_name;
		int L = friend_name.size();

		while (!q[L].empty() && (i - q[L].front()) > K)
			q[L].pop();

		ans += q[L].size();
		q[L].push(i);
	}
	cout << ans;
}