#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int N, d;

bool compare(pii p1, pii p2) {
	if (p1.first == p2.first)
		return p1.second > p2.second;
	else
		return p1.first < p2.first;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N;
	vector<pii> v;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		v.push_back(pii(a, b));
	}
	cin >> d;

	vector<pii> v2;
	for (pii p : v) {
		if (p.second - p.first <= d) {
			v2.push_back(pii(p.first, -1));
			v2.push_back(pii(p.second - d, 1));
		}
	}
	sort(v2.begin(), v2.end(), compare);

	int cnt = 0, ans = 0;
	for (pii p : v2) {
		cnt += p.second;
		ans = max(ans, cnt);
	}
	cout << ans;
}