#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
ll k, ans;
ll w[1 << 21];
ll S[1 << 21];

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> k;
	for (int i = 2; i < (1 << k + 1); i++) {
		cin >> w[i];
		ans += w[i];
		w[i] += w[i >> 1];
	}
	ll max_w = 0;
	for (int i = 1 << k; i < (1 << k + 1); i++) {
		max_w = max(max_w, w[i]);
	}
	for (int i = 1 << k; i < (1 << k + 1); i++) {
		S[i] = max_w - w[i];
	}
	for (int i = (1 << k) - 1; i > 0; i--) {
		S[i] = min(S[i << 1], S[(i << 1) + 1]);
		S[i << 1] -= S[i];
		S[(i << 1) + 1] -= S[i];
	}
	for (int i = 1; i < (1 << k + 1); i++) {
		ans += S[i];
	}
	cout << ans << endl;
}