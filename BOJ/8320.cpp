#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) ret++;
        }
    }
    cout << ret << endl;
}