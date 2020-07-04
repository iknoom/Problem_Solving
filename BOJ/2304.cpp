#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> tt;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	vector<tt> stack, v;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int l, h;
		cin >> l >> h;
		v.push_back(tt(l, h)); // 위치, 높이
	}

	sort(v.begin(), v.end());

	tt maxh(-1,-1);

	for (int i = 0; i < N; i++) {

		if (stack.empty()) {
			stack.push_back(v[i]);
			maxh = v[i];
		}
		else if (maxh.second < v[i].second) { // 최대 높이보다 클 때
			while (stack.back().second < maxh.second)
				stack.pop_back();
			stack.push_back(v[i]);
			maxh = v[i];
		}
		else { // 최대 높이보다 작을 때
			while (stack.back().second < v[i].second)
				stack.pop_back();
			stack.push_back(v[i]);
		}
	}
	int ans = 0;
	tt prvh(-1, 0); // 이전 기둥의 위치, 높이

	for (auto curh : stack) {
		int w, h;
		w = curh.first - prvh.first;
		if (curh.first <= maxh.first)
			h = prvh.second; // 최대 높이 이전 기둥 -> 이전 기둥 높이
		else
			h = curh.second; // 최대 높이 이후 기둥 -> 현재 기둥 높이
		ans += w * h;
		prvh = curh;
	}
	cout << ans + maxh.second; // 최대 높이 * 1 만큼 더하기
}