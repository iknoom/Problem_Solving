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
    int N, M, T, K;
    cin >> N >> M >> T >> K;
    vector<pi> stones(T);
    for (int i = 0; i < T; i++) {
        cin >> stones[i].x >> stones[i].y;
    }
    sort(all(stones));

    int i = 0, answer_x = -1, answer_y = -1, answer = -1;
    for (int j = 0; j < T; j++) {
        while (stones[j].x - K > stones[i].x) {
            i++;
        }
        // get cur x
        int cur_x = stones[i].x;
        if (cur_x > N - K) {
            cur_x = N - K;
        }

        vector<int> yset;
        for (int k = i; k <= j; k++) {
            yset.push_back(stones[k].y);
        }

        // get cur y
        sort(all(yset));
        int s = 0;
        for (int e = 0; e < (int)yset.size(); e++) {
            while (yset[e] - K > yset[s]) {
                s++;
            }
            int cur = e - s + 1;
            if (answer < cur) {
                answer = cur;
                answer_x = cur_x;
                answer_y = yset[s];
                if (answer_y > M - K) {
                    answer_y = M - K;
                }
            }
        }
    }

    cout << answer_x << ' ' << answer_y + K << '\n';
    cout << answer << '\n';
}