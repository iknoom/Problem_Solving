#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    string s; long long K;
    cin >> s >> K;
    vector<bool> is_prime(K + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= K; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= K; j += i) {
                is_prime[j] = false;
            }
        }
    }
    long long answer = -1;
    for (long long i = 0; i < K; i++) {
        if (!is_prime[i]) continue;
        long long ret = 0, ten = 1;
        for (int j = 0; j < sz(s); j++) {
            ret += ten * (s[sz(s) - 1 - j] - '0');
            ret %= i;
            ten *= 10;
            ten %= i;
        }
        if (ret == 0) {
            answer = i;
            break;
        }
    }
    if (answer < 0) {
        cout << "GOOD" << '\n';
    } else {
        cout << "BAD " << answer << '\n';
    }
}