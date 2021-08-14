#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const long long INF = 1e18;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N;
long long K, arr[20][20];
vector<long long> same_left_sum[20], same_right_sum[20], lower_left_sum[20], lower_right_sum[20];
vector<long long> tmp;

void dfs(int x, int y, int sign, int cnt) {
    if (cnt == N - 1) {
        tmp.push_back(arr[y][x]);
        long long max_sum = -INF, cur = 0;
        // get max_sub
        for (int i = 0; i < N; i++) {
            if (cur < 0) cur = 0;
            cur += tmp[i];
            max_sum = max(max_sum, cur);
        }
        // push to dp
        if (sign > 0) {
            if (max_sum < K) {
                lower_left_sum[x].push_back(cur);
            }
            if (max_sum == K) {
                same_left_sum[x].push_back(cur);
            }
        }
        if (sign < 0) {
            if (max_sum < K) {
                lower_right_sum[x].push_back(cur);
            }
            if (max_sum == K) {
                same_right_sum[x].push_back(cur);
            }
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back(arr[y][x]);
    dfs(x + sign, y, sign, cnt + 1);
    dfs(x, y + sign, sign, cnt + 1);
    tmp.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    if (N == 1) {
        if (arr[0][0] == K) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return 0;
    }

    // dfs
    dfs(0, 0, 1, 0);
    dfs(N - 1, N - 1, -1, 0);

    // sort
    for (int i = 0; i < N; i++) {
        sort(all(lower_left_sum[i]));
        sort(all(same_left_sum[i]));
        sort(all(lower_right_sum[i]));
        sort(all(same_right_sum[i]));
    }

    // get_answer
    long long answer = 0;
    for (int x = 0; x < N; x++) {
        // case 1
        for (auto right_sum : same_right_sum[x]) {
            answer += upper_bound(all(lower_left_sum[x]), K - right_sum + arr[N - x - 1][x]) - lower_left_sum[x].begin();
        }
        // case 2
        for (auto left_sum : same_left_sum[x]) {
            answer += upper_bound(all(lower_right_sum[x]), K - left_sum + arr[N - x - 1][x]) - lower_right_sum[x].begin();
        }
        // case 3
        for (auto left_sum : same_left_sum[x]) {
            answer += upper_bound(all(same_right_sum[x]), K - left_sum + arr[N - x - 1][x]) - same_right_sum[x].begin();
        }
        // case 4
        for (auto left_sum : lower_left_sum[x]) {
            answer += upper_bound(all(lower_right_sum[x]), K - left_sum + arr[N - x - 1][x]) - lower_bound(all(lower_right_sum[x]), K - left_sum + arr[N - x - 1][x]);
        }
    }
    cout << answer << '\n';
}