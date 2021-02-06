#include <bits/stdc++.h>
using namespace std;
vector<int> al[26];

int main() {
    string S, T;
    cin >> S >> T;
    int cnt = 1, p = 0;
    for (int i = 0; i < T.size(); i++) al[T[i] - 'a'].push_back(i);
    for (auto k : S) {
        int a = k - 'a';
        if (al[a].empty()) {
            cout << -1 << '\n';
            return 0;
        }
        auto i = lower_bound(al[a].begin(), al[a].end(), p);
        if (i == al[a].end()) {
            cnt++; p = al[a].front() + 1;
        } else {
            p = (*i) + 1;
        }
    }
    cout << cnt << '\n';
}