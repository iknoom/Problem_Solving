#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;
using pi = pair<ll, ll>;

int N, M, R;
ll max_profit[100000];
ll ans;

int main()
{
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	cin >> N >> M >> R;
	vector<ll> produced_mk(N), renting_pc(R);
	vector<pi> stores(M);
	for (int i = 0; i < N; i++) 
		cin >> produced_mk[i];
	for (int i = 0; i < M; i++) 
		cin >> stores[i].second >> stores[i].first;
	for (int i = 0; i < R; i++) 
		cin >> renting_pc[i];

	sort(produced_mk.begin(), produced_mk.end());
	sort(stores.begin(), stores.end(), greater<pi>());
	sort(renting_pc.begin(), renting_pc.end(), greater<ll>());
	fill(max_profit, max_profit + N, 0);

	for (int i = 0; i < min(R, N); i++) {
		max_profit[i] = renting_pc[i];
		ans += renting_pc[i];
	}

	int j = 0;
	for (int i = N - 1; i >= 0; i--) {
		ll t = produced_mk[i];
		ll tmp = 0;
		while (j < M && stores[j].second < t) {
			t -= stores[j].second;
			tmp += stores[j].first * stores[j].second;
			j++;
		}
		if (j < M) {
			stores[j].second -= t;
			tmp += stores[j].first * t;
		}
		if (max_profit[i] < tmp) {
			ans += tmp - max_profit[i];
		}
		if (j >= M)
			break;
	}
	cout << ans << endl;
}
