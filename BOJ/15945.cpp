#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1e18;
int main() {
    int N;
    cin >> N;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // default
    long long min_value = INF, max_value = -INF;
    bool flag = false;
    for (auto k : v) {
        if (k == 0) continue;
        min_value = min(min_value, k);
        max_value = max(max_value, k);
        flag = true;
    }

    if (!flag) {
        cout << 0 << '\n';
        return 0;
    }

    long long answer = abs(max_value - min_value);
    if (max_value > 0 && min_value < 0) {
        cout << 0 << '\n';
    } else if (max_value < 0) {
        cout << min(answer, abs(max_value)) << '\n';
    } else {
        cout << min(answer, min_value) << '\n';
    }
}