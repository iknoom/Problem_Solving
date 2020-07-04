#include <iostream>
#include <queue>
using namespace std;
int T, N;

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		priority_queue<int, vector<int>, less<int>> heap1;
		priority_queue<int, vector<int>, greater<int>> heap2;
		cin >> N;
		cout << (N+1) / 2 << '\n';
		int tmp;
		cin >> tmp;
		cout << tmp << ' ';
		heap1.push(tmp);

		for (int i = 2; i <= N; i++) {
			if (i % 20 == 0) cout << '\n';
			cin >> tmp;
			if (heap1.top() < tmp) heap2.push(tmp);
			else heap1.push(tmp);

			if (heap1.size() < heap2.size()) {
				heap1.push(heap2.top());
				heap2.pop();
			}

			else if (heap1.size() - 1 > heap2.size()) {
				heap2.push(heap1.top());
				heap1.pop();
			}
			if(i & 1) cout << heap1.top() << ' ';
		}
		cout << '\n';
	}
}
