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

void solution() {
    int A = 0, B = 0;
    for (int i = 0; i < 9; i++) {
        int a, b;
        cin >> a >> b;
        A += a; B += b;
    }
    if (A > B) {
        cout << "Yonsei" <<'\n';
    } else if (A < B) {
        cout << "Korea" <<'\n';
    } else {
        cout << "Draw" <<'\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}