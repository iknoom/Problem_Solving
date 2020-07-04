#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const int INF = 1e9 + 3;
const int SIZE = 1 << 17;
int seg[SIZE << 1];
int N, M;

void init() {
	for (int i = SIZE - 1; i > 0; i--) {
		seg[i] = min(seg[i << 1], seg[i << 1 | 1]);
	}
}

int seg_min(int s, int e, int i, int ns, int ne) {
	if (ne < s || e < ns) return INF;
	if (s <= ns && ne <= e) return seg[i];
	int mid = (ns + ne) >> 1;
	return min(seg_min(s, e, i << 1, ns, mid), seg_min(s, e, i << 1 | 1, mid + 1, ne));
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	fill(seg, seg + (SIZE << 1), INF);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> seg[SIZE + i];
	
	init();

	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << seg_min(a - 1, b - 1, 1, 0, SIZE - 1) << '\n';
	}

}
