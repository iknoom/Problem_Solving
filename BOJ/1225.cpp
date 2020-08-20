#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    string A, B;
    cin >> A >> B;
    long long S1 = 0, S2 = 0;
    for (auto k : A) S1 += k - '0';
    for (auto k : B) S2 += k - '0';
    cout << S1 * S2 << endl;
}