#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    while (N > 1) {
        if (N & 1) {
            cout << 0 << endl;
            return 0;
        }
        N /= 2;
    }
    cout << 1 << endl;
}