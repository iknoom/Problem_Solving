#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> time;
int N;
vector<time> v;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		a = a / 100 * 60 + a % 100;
		b = b / 100 * 60 + b % 100;
		v.push_back(time(a - 10, b + 10));
	}
	sort(v.begin(), v.end());

	int ans = 0, start_time = 600, end_time = 600;
	for (time T : v) {
		if (end_time < T.first) {
			ans = max(ans, T.first - end_time);
			start_time = T.first;
			end_time = T.second;
		}
		else end_time = max(end_time, T.second);
	}
	ans = max(ans, 1320 - end_time);
	cout << ans << endl;
}