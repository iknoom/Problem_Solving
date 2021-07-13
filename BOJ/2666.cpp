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
    int N, open1, open2, Q;
    cin >> N;
    cin >> open1 >> open2;
    cin >> Q;
    vector<int> arr(Q);
    for (int i = 0; i < Q; i++) {
        cin >> arr[i];
    }

    int answer = 1e9;
    for (int i = 0; i < (1 << Q); i++) {
        int cur = 0, u = open1, v = open2;
        for (int j = 0; j < Q; j++) {
            if (i & (1 << j)) {
                cur += abs(u - arr[j]);
                u = arr[j];
            } else {
                cur += abs(v - arr[j]);
                v = arr[j];
            }
        }
        answer = min(answer, cur);
    }
    cout << answer << '\n';
}