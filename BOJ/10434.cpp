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

vector<bool> get_is_happy(int n) {
    vector<bool> is_happy(n + 1), vst(n + 1);
    is_happy[1] = true;
    vst[1] = true;
    for (int i = 2; i <= n; i++) {
        int u = i;
        vector<int> backtrack;
        while (true) {
            if (vst[u]) {
                for (auto k : backtrack) {
                    is_happy[k] = is_happy[u];
                }
                break;
            }
            vst[u] = true;
            backtrack.push_back(u);
            int nxt = 0;
            while (u) {
                nxt += (u % 10) * (u % 10);
                u /= 10;
            }
            u = nxt;
        }
    }
    return is_happy;
}

vector<bool> get_is_prime(int n) {
    vector<bool> ret(n + 1, true);
    ret[0] = ret[1] = false;
    for (int i = 2; i <= n; i++) {
        if (ret[i]) {
            for (int j = i * 2; j <= n; j += i) {
                ret[j] = false;
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<bool> is_happy = get_is_happy(10000);
    vector<bool> is_prime = get_is_prime(10000);

    int P;
    cin >> P;
    while (P--) {
        int i, M;
        cin >> i >> M;
        cout << i << ' ' << M << ' ';
        if (is_happy[M] && is_prime[M]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}