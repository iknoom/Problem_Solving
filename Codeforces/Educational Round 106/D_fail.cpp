#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

void solution() {
    int c, d, x;
    cin >> c >> d >> x;
    vector<int> gset;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i * i == x) {
                gset.push_back(i);
            } else {
                gset.push_back(i);
                gset.push_back(x / i);
            }
        }
    }
    // solution
    int answer = 0;
    for (auto g : gset) {
        int right = g;
        right += d;
        if (right % c != 0) {
            continue;
        }
        right /= c;
        vector<int> fac;
        int ret = 1;
        for (int i = 2; i * i <= right; i++) {
            if (right % i == 0) {
                ret *= 2;
                while (right % i == 0) right /= i;
            }
        }
        if (right > 1){
            ret *= 2;
            fac.push_back(right);
        }
        answer += ret;
    }
    cout << answer << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}