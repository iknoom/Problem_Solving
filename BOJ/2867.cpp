#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<ll, int> tt;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	vector<ll> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	ll ans = 0;
	vector<tt> max_stack;
	v.push_back(100000001);
	for (int i = 0; i < N+1; i++) { // 최댓값
		while (!max_stack.empty() && max_stack.back().first <= v[i]) {
			tt top = max_stack.back();
			max_stack.pop_back();
			ll a, b;
			if (!max_stack.empty()) {
				a = top.second - max_stack.back().second; // 좌측 큰 값과의 index 차이
				b = i + 1 - top.second; // 우측 큰 값과의 index 차이
			}
			else {
				a = top.second; // 좌측에 큰 값이 없으므로 차이는 index - 0
				b = i + 1 - top.second; // 우측 큰 값과의 index 차이
			}
			ans += top.first * a * b;
		}
		max_stack.push_back(tt(v[i], i + 1)); // 원소의 값, 원소의 index+1
	}
	vector<tt> min_stack;
	v.back() = 0;
	for (int i = 0; i < N+1; i++) { // 최솟값
		while (!min_stack.empty() && min_stack.back().first >= v[i]) {
			tt top = min_stack.back();
			min_stack.pop_back();
			ll a, b;
			if (!min_stack.empty()) {
				a = top.second - min_stack.back().second;
				b = i + 1 - top.second;
			}
			else {
				a = top.second;
				b = i + 1 - top.second;
			}
			ans -= top.first * a * b;
		}
		min_stack.push_back(tt(v[i], i + 1));
	}
	cout << ans << endl;
}