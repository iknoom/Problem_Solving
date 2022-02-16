#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, answer = 0;
    cin >> N;
    vector<int> prefixSum(N + 1);
    for (int i = 0; i < N; i++) {
        int X_i, Y_i;
        cin >> X_i >> Y_i;
        int S = prefixSum[i] - prefixSum[i - X_i];
        prefixSum[i + 1] = prefixSum[i];
        if (S >= Y_i) {
            answer++;
            prefixSum[i + 1]++;
        }
    }
    cout << answer << '\n';
}