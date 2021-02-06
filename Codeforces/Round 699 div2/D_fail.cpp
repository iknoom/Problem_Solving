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

void solution() {
    int n, m;
    cin >> n >> m;
    vector<string> adj(n);
    for (int i = 0 ; i < n; i++) cin >> adj[i];

    // m % 2 == 1
    if (m & 1) {
        cout << "YES" << '\n';
        cout << 1 << '\n';
        for (int i = 0; i < (m / 2); i++) {
            cout << 2 << ' ' << 1 << ' ';
        }
        cout << 2 << '\n';
        return;
    }

    // m == 2
    if (n == 2) {
        if (adj[0][1] == adj[1][0]) {
            cout << "YES" << '\n';
            cout << 2 << ' ';
            for (int i = 0; i < (m / 2); i++) {
                cout << 1 << ' ' << 2 << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
        return;
    }

    // m >= 4
    for (int i = 0; i < n; i++) {
        int aa = -1, ab = -1, bb = -1, ba = -1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (adj[i][j] == 'a' && adj[j][i] == 'a') {
                aa = j;
            }
            if (adj[i][j] == 'a' && adj[j][i] == 'b') {
                ab = j;
            }
            if (adj[i][j] == 'b' && adj[j][i] == 'a') {
                ba = j;
            }
            if (adj[i][j] == 'b' && adj[j][i] == 'b') {
                bb = j;
            }
        }


    }
    cout << "NO" << '\n';
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
}