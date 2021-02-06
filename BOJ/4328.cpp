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
    while (true) {
        long long b, mod = 0;
        string p, m;
        cin >> b;
        if (b == 0) break;
        cin >> p >> m;
        // get mod
        long long pow = 1;
        for (int i = m.size() - 1; i >= 0; i--) {
            mod += (m[i] - '0') * pow;
            pow *= b;
        }
        // get p
        vector<long long> tmp;
        pow = 1;
        for (int i = p.size() - 1; i >= 0; i--) {
            long long val = (p[i] - '0') * pow;
            tmp.push_back(val % mod);
            pow *= b;
            pow %= mod;
        }
        // get 10's val
        long long ret = 0;
        for (auto k : tmp) {
            ret += k;
            ret %= mod;
        }
        // get b's val
        pow = 1;
        while (pow * b <= ret) pow *= b;
        while (pow) {
            cout << ret / pow;
            ret %= pow;
            pow /= b;
        }
        cout << '\n';
    }
}