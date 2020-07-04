#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pi = pair<int, int>;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

char B[12][6];
bool vst[12][6];
vector<pi> stack;

void bfs(int y, int x) {
	queue<pi> q;
	int cnt = 0;
	vst[y][x] = true;
	q.push({ x, y });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		cnt++;
		stack.push_back({ a,b });

		for (int i = 0; i < 4; i++) {
			int xx = a + dx[i];
			int yy = b + dy[i];
			if (0 <= xx && xx < 6 && 0 <= yy && yy < 12
				&& !vst[yy][xx] && B[yy][xx] == B[b][a]) {
				vst[yy][xx] = true;
				q.push({ xx, yy });
			}
		}
	}
	if (cnt < 4) {
		while (cnt--) {
			stack.pop_back();
		}
	}
}

void push_down() {
	for (int j = 0; j < 6; j++) {
		vector<char> v;
		for (int i = 0; i < 12; i++) {
			if (B[i][j] != '.') v.push_back(B[i][j]);
		}
		for (int i = 11; 0 <= i; i--) {
			if (v.empty()) B[i][j] = '.';
			else {
				B[i][j] = v.back();
				v.pop_back();
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			B[i][j] = cin.get();
		}
		cin.get();
	}

	int ans = 0;
	while (true) {
		for (int i = 0; i < 12; i++)
			fill(vst[i], vst[i] + 6, false);

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++) {
				if (B[i][j] != '.' && !vst[i][j])
					bfs(i, j);
			}

		if (stack.empty())
			break;
		else {
			ans++;
			for (auto k : stack) B[k.second][k.first] = '.';
			stack.clear();
			push_down();
		}
	}
	cout << ans << endl;
}
