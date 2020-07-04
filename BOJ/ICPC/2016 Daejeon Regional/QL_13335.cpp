#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
ll n, w, L, a[1000], hw[100];

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll j = 0, cnt = 0, t = 0, S = 0;

	while (cnt < n) {
		if (hw[0]) {
			S -= hw[0];
			cnt++;
		}
		for (int i = 0; i < w - 1; i++) {
			hw[i] = hw[i + 1];
		}
		if (j < n && S + a[j] <= L) {
			S += a[j];
			hw[w - 1] = a[j];
			j++;
		}
		else
			hw[w - 1] = 0;
		t++;
	}
	cout << t << endl;
}