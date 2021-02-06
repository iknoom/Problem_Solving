#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    reverse(v.begin(), v.end());
    int ret = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i - 1] > v[i]) continue;
        ret += v[i] - (v[i - 1] - 1);
        v[i] = (v[i - 1] - 1);
    }
    cout << ret << '\n';
}