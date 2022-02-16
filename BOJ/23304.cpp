#include <bits/stdc++.h>

using namespace std;

bool solution(string &S) {
    if (S.size() == 1) {
        return true;
    }
    for (int i = 0; i < S.size(); i++) {
        if (S[i] != S[S.size() - 1 - i]) {
            return false;
        }
    }
    string pre = S.substr(0, S.size() / 2);
    string suf = S.substr(S.size() - S.size() / 2, S.size() / 2);
    return solution(pre) && solution(suf);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    if (solution(S)) {
        cout << "AKARAKA" << '\n';
    } else {
        cout << "IPSELENTI" << '\n';
    }
}