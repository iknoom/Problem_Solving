#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int N;
    cin >> N;
    vector<int> points[50];
    for (int i = 0; i < N; i++) {
        points[i].resize(9);
        for (int j = 0; j < 9; j++) {
            cin >> points[i][j];
        }
    }
    vector<int> idx;
    for (int i = 1; i < 9; i++) {
        idx.push_back(i);
    }

    int answer = -1;
    do {
        queue<int> q;
        for (int i = 0; i < 3; i++) q.push(idx[i]);
        q.push(0);
        for (int i = 3; i < 8; i++) q.push(idx[i]);
        // simulation
        int cur = 0;
        for (int i = 0; i < N; i++) {
            int out = 0;
            vector<int> triple(3, 0);
            while (out < 3) {
                int u = q.front();
                q.pop();
                int point = points[i][u];
                if (point == 0) {
                    out++;
                } else if (point == 4) {
                    for (int j = 0; j < 3; j++) {
                        if (triple[j]) {
                            triple[j] = 0;
                            cur++;
                        }
                    }
                    cur++;
                } else {
                    for (int j = 2; j >= 0; j--) {
                        if (!triple[j]) continue;
                        if (j + point >= 3) {
                            cur++;
                        } else {
                            triple[j + point] = 1;
                        }
                        triple[j] = 0;
                    }
                    triple[point - 1] = 1;
                }
                q.push(u);
            }
        }
        answer = max(answer, cur);
    } while (next_permutation(all(idx)));
    cout << answer << '\n';
}