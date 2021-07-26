#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    long long N;
    cin >> N;
    vector<long long> v(7);
    for (int i = 1; i <= 6; i++) {
        cin >> v[i];
    }
    v[0] = INF;

    long long one = INF, two = INF, three = INF;
    one = *min_element(all(v));

    two = min(two, v[1] + v[2]);
    two = min(two, v[1] + v[3]);
    two = min(two, v[1] + v[4]);
    two = min(two, v[1] + v[5]);
    two = min(two, v[2] + v[3]);
    two = min(two, v[2] + v[4]);
    two = min(two, v[2] + v[6]);
    two = min(two, v[3] + v[5]);
    two = min(two, v[3] + v[6]);
    two = min(two, v[4] + v[5]);
    two = min(two, v[4] + v[6]);
    two = min(two, v[5] + v[6]);

    three = min(three, v[1] + v[2] + v[3]);
    three = min(three, v[1] + v[3] + v[5]);
    three = min(three, v[1] + v[2] + v[4]);
    three = min(three, v[1] + v[4] + v[5]);
    three = min(three, v[6] + v[2] + v[3]);
    three = min(three, v[6] + v[3] + v[5]);
    three = min(three, v[6] + v[2] + v[4]);
    three = min(three, v[6] + v[4] + v[5]);

    if (N == 1) {
        long long S = 0;
        for (int i = 1; i <= 6; i++) {
            S += v[i];
        }
        cout << S - *max_element(v.begin() + 1, v.end()) << '\n';
    } else {
        long long area = (N - 2) * (N - 2) * 5 * one + (N - 2) * 4 * one;
        long long edge = ((N - 2) * 4 + (N - 1) * 4) * two;
        long long vertex = 4 * three;
        cout << area + edge + vertex << '\n';

    }
}