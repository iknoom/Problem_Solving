#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
ll n;
ll idx[1000];
int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> idx[i];

	for (int k = 0; k <= n; k++) {
		ll a = 0, b = 0;
		for (int j = 0; j < n; j++) {
			if (idx[j] == k) a++;
			if (idx[j] < k) b++;
		}
		if (b <= n - k && a + b >= n - k) {
			cout << k << endl;
			return 0;
		}
	}
}