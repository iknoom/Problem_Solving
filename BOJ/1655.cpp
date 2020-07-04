#include <iostream>
#include <queue>
using namespace std;
int N;
priority_queue<int, vector<int>, less<int>> heap1;
priority_queue<int, vector<int>, greater<int>> heap2;

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int tmp;
	cin >> tmp;
	cout << tmp << '\n';
	heap1.push(tmp);

	for (int i = 2; i <= N; i++) {
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
	}
}
