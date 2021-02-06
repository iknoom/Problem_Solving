#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    N += 56;
    string A = "0123456789";
    string B = "ABCDEFGHIJKL";
    cout << B[N%12] << A[N%10] << '\n';
}