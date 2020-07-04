#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> point;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<point> v;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(point(a, 1));
		v.push_back(point(b, -1));
	}
	int cnt = 0;
	int ans = -1;
	sort(v.begin(), v.end());
	for (point i : v) {
		cnt += i.second;
		if (cnt > ans)
			ans = cnt;
	}
	cout << ans;
}