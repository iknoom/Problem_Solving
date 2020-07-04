#include <iostream>
using namespace std;
int main() {
	int T, N, M, a, b;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		while (M--) cin >> a >> b;
		cout << N - 1 << '\n';
	}
}