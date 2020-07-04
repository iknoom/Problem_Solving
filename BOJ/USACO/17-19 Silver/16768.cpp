#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pi = pair<int, int>;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int N, K, B[100][10];
bool vst[100][10];
vector<pi> stack;


void print_B() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cout << B[i][j];
        }
        cout << endl;
    }
}

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
            if (0 <= xx && xx < 10 && 0 <= yy && yy < N
                && !vst[yy][xx] && B[yy][xx] == B[b][a]) {
                vst[yy][xx] = true;
                q.push({ xx, yy });
            }
        }
    }
    if (cnt < K) {
        while (cnt--) {
            stack.pop_back();
        }
    }
}

void push_down() {
    for (int j = 0; j < 10; j++) {
        vector<int> v;
        for (int i = 0; i < N; i++) {
            if (B[i][j]) v.push_back(B[i][j]);
        }
        for (int i = N - 1; 0 <= i; i--) {
            if (v.empty()) B[i][j] = 0;
            else {
                B[i][j] = v.back();
                v.pop_back();
            }
        }
    }
}

int main()
{
    cin >> N >> K;
    cin.get();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            char c = cin.get();
            B[i][j] = c - 48;
        }
        cin.get();
    }

    while (true) {
        for (int i = 0; i < N; i++)
            fill(vst[i], vst[i] + 10, false);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < 10; j++) {
                if (B[i][j] && !vst[i][j])
                    bfs(i, j);
            }

        if (stack.empty())
            break;
        else {
            for (auto k : stack) B[k.second][k.first] = 0;
            stack.clear();
            push_down();
        }
    }
    print_B();
}
