#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<long long, long long>;
const long long INF = 1e18;

long long get_abs_sum(vector<long long> &diff, long long xy) {
    long long ret = 0;
    for (int i = 0; i < 8; i++) {
        ret += abs(diff[i] + xy);
    }
    return ret;
}

void solution() {
    // input
    long long K;
    cin >> K;
    vector<pi> points(8);
    vector<int> v(8);
    for (int i = 0; i < 8; i++) {
        cin >> points[i].x >> points[i].y;
        v[i] = i;
    }
    // set des
    vector<pi> des = {
            {0,     0},
            {0,     K},
            {K,     2 * K},
            {2 * K, 2 * K},
            {3 * K, K},
            {3 * K, 0},
            {2 * K, -K},
            {K, -K}
    };

    // solution
    long long answer = INF;
    do {
        vector<long long> xdiff(8), ydiff(8);
        for (int i = 0; i < 8; i++) {
            xdiff[i] = des[i].x - points[v[i]].x;
            ydiff[i] = des[i].y - points[v[i]].y;
        }
        long long curx = INF, cury = INF;
        // get x
        for(long long i = 0; i < 8; i++) {
            curx = min(curx, get_abs_sum(xdiff, -xdiff[i]));
        }
        // get y
        for(long long i = 0; i < 8; i++) {
            cury = min(cury, get_abs_sum(ydiff, -ydiff[i]));
        }
        answer = min(answer, curx + cury);
    } while(next_permutation(v.begin(), v.end()));

    cout << answer << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << '\n';
        solution();
    }
}