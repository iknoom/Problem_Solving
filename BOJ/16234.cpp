#include <iostream>
#include <algorithm>
using namespace std;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
int N, L, R, cnt;
int Sp, Sn, nxt;
int PM[50][50];
int opened[50][50][4];
int vst[50][50];

void init() {
	for (int j = 0; j < N; j++) for (int i = 0; i < N; i++) {
		fill(opened[j][i], opened[j][i] + 4, 0);
	}
}

void open() {
	for (int y = 0; y < N; y++) for (int x = 0; x < N; x++) {
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if (0 <= a && a < N && 0 <= b && b < N) {
				int D = abs(PM[y][x] - PM[b][a]);
				if (L <= D && D <= R) {
					opened[y][x][i] = 1;
				}
			}
		}
	}
}

void move(int x, int y) {
	vst[y][x] = 0;
	PM[y][x] = nxt;
	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];
		if (0 <= a && a < N && 0 <= b && b < N && vst[b][a] && opened[y][x][i]) {
			move(a, b);
		}
			
	}
}

void dfs(int x, int y) {
	vst[y][x] = 1;
	Sp += PM[y][x];
	Sn += 1;
	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];
		if (0 <= a && a < N && 0 <= b && b < N && !(vst[b][a]) && opened[y][x][i])
			dfs(a, b);
	}
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> N >> L >> R;
	for (int j = 0; j < N; j++) for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		PM[j][i] = t;
	}
	cnt = 0;
	while (1) {
		int flag = 0;
		init();
		open();
		for (int j = 0; j < N; j++) for (int i = 0; i < N; i++) {
			Sp = 0, Sn = 0;
			if (!vst[j][i]) {
				dfs(i, j);
				if (Sn > 1) {
					nxt = Sp / Sn;
					move(i, j);
					flag = 1;
				}
				else
					vst[j][i] = 0;
			}
		}

		if (flag) cnt += 1;
		else break;
	}
	cout << cnt << endl;
}