#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> S(5);
    for (int i = 0; i < 5; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < sz(S[0]); i++) {
        if (S[2][i] == 'm') {
            S[0][i] = 'o';
            S[1][i] = 'w';
            S[2][i] = 'l';
            S[3][i] = 'n';
            S[4][i] = '.';
        } else if (S[1][i] == 'w') {
            S[0][i] = '.';
            S[1][i] = 'o';
            S[2][i] = 'm';
            S[3][i] = 'l';
            S[4][i] = 'n';
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << S[i] << '\n';
    }
}