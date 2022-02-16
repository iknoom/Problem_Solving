#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ti = tuple<int, int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ti> arr;
    for (int i = 0; i < n; i++) {
        int b_i, p_i, q_i, r_i;
        cin >> b_i >> p_i >> q_i >> r_i;
        arr.emplace_back(p_i * q_i * r_i, p_i + q_i + r_i, b_i);
    }
    sort(all(arr));
    for (int i = 0; i < 3; i++) {
        auto [s1, s2, b_i] = arr[i];
        cout << b_i << ' ';
    }
}