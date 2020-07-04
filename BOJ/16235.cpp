#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };

typedef struct tree {
	int x, y, z;
}tr;

deque<tr> trees;

int N, M, K;
int A[10][10];
int B[10][10];
int PM[10][10];

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> N >> M >> K;

	for (int j = 0; j < N; j++) for (int i = 0; i < N; i++) {
		cin >> A[j][i];
		B[j][i] = 5;
		PM[j][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int r, c, z;
		cin >> r >> c >> z;
		trees.push_back({ c - 1, r - 1, z });
	}

	while (K--) {
		deque<tr> tmp;
		for (auto tree : trees) {
			if (tree.z <= B[tree.y][tree.x]) {
				B[tree.y][tree.x] -= tree.z;
				tmp.push_back({ tree.x,tree.y,tree.z + 1 });

				if ((tree.z + 1) % 5 == 0) {
					for (int i = 0; i < 8; i++) {
						int xx, yy;
						xx = tree.x + dx[i]; yy = tree.y + dy[i];
						if (0 <= xx && xx < N && 0 <= yy && yy < N)
							tmp.push_front({ xx,yy,1 });
					}
				}
			}
			else PM[tree.y][tree.x] += tree.z / 2;	
		}

		for (int j = 0; j < N; j++) for (int i = 0; i < N; i++) {
			B[j][i] += A[j][i] + PM[j][i];
			PM[j][i] = 0;
		}
		trees.clear();
		trees.assign(tmp.begin(), tmp.end());
	}
	cout << trees.size() << endl;
}

