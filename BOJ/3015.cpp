#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<long long, int> tt;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	vector<long long> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	long long ans = 0, ans2 = 0;
	vector<tt> stack;
	for (int i = 0; i < N; i++) {
		while (!stack.empty() && stack.back().first < v[i]) {
			ans += stack.back().second;
			stack.pop_back();
		}
		if (!stack.empty() && stack.back().first == v[i]) {
			ans2 += stack.back().second;
			stack.back().second += 1;
		}
		else
			stack.push_back(tt(v[i], 1));
	}
	stack.clear();
	for (int i = N - 1; i >= 0; i--) {
		while (!stack.empty() && stack.back().first < v[i]) {
			ans += stack.back().second;
			stack.pop_back();
		}
		if (!stack.empty() && stack.back().first == v[i]) {
			ans2 += stack.back().second;
			stack.back().second += 1;
		}
		else
			stack.push_back(tt(v[i], 1));
	}
	cout << ans + ans2 / 2 << endl;
}