#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;

	cin >> N;
	vector<int> stack;
	vector<int> v(N), ans(N);

	for (int i = 0; i < N; i++) cin >> v[i];

	for(int i = N - 1; i >= 0; i--) {
		int cur = v[i];
		while (!stack.empty() && stack.back() <= cur) {
			stack.pop_back();
		}

		if (stack.empty()) ans[i] = -1;
		else ans[i] = stack.back();

		stack.push_back(cur);
	}
	
	for (auto i : ans) cout << i << ' ';
}