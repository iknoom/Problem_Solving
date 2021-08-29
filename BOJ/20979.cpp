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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, A;
    cin >> N >> A;
    string S;
    cin >> S;

    A--;
    long long answer = 0;
    int l = A, r = A, flag = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '#') cnt++;
    }
    while (cnt) {
        // cout << S << ' ' << l << ' ' << r << '\n';
        if (flag == 0) {
            while (r < N && S[r] != '#') {
                r++;
            }
            if (r < N) {
                S[r] = '.';
                cnt--;
            }
            answer += r - A;
            A = r;
        } else {
            while (l >= 0 && S[l] != '#') {
                l--;
            }
            if (l >= 0) {
                S[l] = '.';
                cnt--;
            }
            answer += A - l;
            A = l;
        }
        flag ^= 1;
    }
    cout << answer << '\n';
}