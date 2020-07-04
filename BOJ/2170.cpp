#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> line;
int N;
vector<line> v;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(line(a, b));
	}
	sort(v.begin(), v.end());
	
	int start_point = -1000000001, end_point = -1000000001, ans = 0;
	for (line L : v) {
		if (end_point < L.first) {
			ans += end_point - start_point;
			start_point = L.first;
			end_point = L.second;
		}
		else end_point = max(end_point, L.second);
	}
	ans += end_point - start_point;

	cout << ans << endl;
}