#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, k, l, dp1[10001], dp2[10001];
const int INF = 1e9;

bool is_theta(int w, int u) {
	return k * w <= 2 * u * l;
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n >> k >> l;
	string A;
	cin >> A;
	fill(dp2 + 1, dp2 + n + 1, INF);
	for (int i = 2; i <= n; i++) {
		int tmp = 0;
		for (int j = i - 1; j > 0; j--) {
			if (A[j - 1] == A[i - 1]) {
				swap(dp1[j], tmp);
				dp1[j]++;
				if (is_theta(i - j + 1, dp1[j])) {
					dp2[i] = min(dp2[i], dp2[j - 1] + 1);
				}
			}
			else {
				tmp = dp1[j];
				dp1[j] = 0;
			}
		}
	}
	if (dp2[n] == INF) cout << 0 << endl;
	else cout << dp2[n] << endl;
}