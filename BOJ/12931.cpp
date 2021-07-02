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
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    int max_double = 0, add_count = 0;
    for (auto b : B) {
        int cur_double = 0;
        for (int i = 1; i <= b; i <<= 1) {
            if (b & i) add_count++;
            cur_double++;
        }
        cur_double--;
        max_double = max(max_double, cur_double);
    }
    cout << max_double + add_count << '\n';
}