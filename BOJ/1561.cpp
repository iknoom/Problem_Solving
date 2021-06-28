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
    long long N;
    int M;
    cin >> N >> M;
    vector<int> times(M);
    for (int i = 0; i < M; i++) {
        cin >> times[i];
    }

    // N보다 작으면서 가장 큰 시간
    long long l = 0, r = 1e12;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        long long cur = 0;
        for (auto time : times) {
            cur += mid / time;
            if (mid % time) cur++;
        }
        if (cur < N) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int before = 0;
    vector<int> nxt;
    for (int i = 0; i < M; i++) {
        int time = times[i];
        before += l / time;
        if (l % time) {
            before++;
        } else {
            nxt.push_back(i);
        }
    }
    cout << nxt[N - before - 1] + 1 << '\n';
}