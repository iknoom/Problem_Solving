#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
map<ll, ll> S;
ll T, N;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N;
		while (N--) {
			char tmp;
			ll num;
			cin >> tmp;
			cin >> num;

			if (tmp == 'I') {
				if (S.find(num) != S.end())
					S[num]++;
				else
					S[num] = 1;
			}

			else if (tmp == 'D') {
				if (S.empty()) continue;
				ll d;
				if (num == -1)
					d = S.begin()->first;
				else if (num == 1)
					d = S.rbegin()->first;

				if (S[d] == 1)
					S.erase(d);
				else
					S[d]--;
			}

		}
		if (S.empty())
			cout << "EMPTY" << '\n';
		else
			cout << S.rbegin()->first << ' ' << S.begin()->first << '\n';
	}
}