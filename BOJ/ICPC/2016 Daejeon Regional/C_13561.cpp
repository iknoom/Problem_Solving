#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
using pi = pair<int, int>;
const int MAX = 2e9;
pi lo[1000000];
int k, n;

int check(int d) {
	vector<int> cnt(n, 0);
	int i = 0, S = 0;
	for (int j = 0; j < n; j++) {
		if (cnt[lo[j].second - 1] == 0) S++;
		cnt[lo[j].second - 1]++;
		while (lo[i].first + d < lo[j].first - d) {
			if (cnt[lo[i].second - 1] == 1) S--;
			cnt[lo[i].second - 1]--;
			i++;
		}
		if (S == k) return lo[j].first - d;
	}
	return MAX;
}

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	cin >> k >> n;
	for (int i = 0; i < n; i++) {
		cin >> lo[i].first >> lo[i].second;
	}
	sort(lo, lo + n);


	int L = -1, R = 1e9;
	while (L + 1 < R) {
		int mid = (L + R) / 2;
		if (check(mid) != MAX) R = mid;
		else L = mid;
	}
	cout << check(R) << endl;
}

