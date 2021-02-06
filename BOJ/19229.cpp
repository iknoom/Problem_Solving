#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, l, k;
    string answer[1000], nl;

    cin >> n >> l >> k;
    cin >> nl;
    sort(nl.begin(), nl.end());

    int i = 0, j = k - 1, p = 0;
    for (int loop = 0; loop < l; loop++) {
        if (i == j) {
            while (answer[j].size() < l)
                answer[j].push_back(nl[p++]);
            break;
        }
        while (i <= j)
            answer[i++].push_back(nl[p++]);
        i--;
        while (i > 0 && answer[i].back() == answer[i - 1].back())
            i--;
    }

    for (i = 0; i < n; i++) {
        while (answer[i].size() < l)
            answer[i].push_back(nl[p++]);
        cout << answer[i] << '\n';
    }
}