#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;


void solution() {
    int n, m;
    cin >> n >> m;
    long long odd_sum = 0, even_sum = 0;
    vector<long long> odd_max_values, even_max_values;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<long long> tmp(l);
        for (int j = 0; j < l; j++) {
            cin >> tmp[j];
        }
        sort(all(tmp));
        long long a = tmp[3], b = tmp[2], c = tmp[1], d = tmp[0];
        if (l % 2 == 0) {
            even_sum += (a + b + c + d);
            even_max_values.push_back(a + b);
        }
        else {
            odd_sum += (a + b + c + d * 2);
            odd_max_values.push_back(a + b);
        }
    }
    if (sz(odd_max_values) == 2 && n > 2) {
        sort(all(odd_max_values), greater<>());
        sort(all(even_max_values), greater<>());
        vector<long long> answer;

        // 0 odd
        long long odd_0 = odd_sum + even_sum - even_max_values[0] - even_max_values[1];
        answer.push_back(odd_0);

        // 1 odd
        long long odd_1 = odd_sum + even_sum - even_max_values[0] - odd_max_values[0];
        answer.push_back(odd_1);

        // 2 odd
        long long odd_2 = odd_sum + even_sum - odd_max_values[0] - odd_max_values[1];
        odd_2 += even_sum;
        for (auto k : even_max_values) {
            odd_2 -= k;
        }
        answer.push_back(odd_2);

        cout << *min_element(all(answer)) << '\n';
    }
    else {
        vector<long long> max_values;
        for (auto k : even_max_values) {
            max_values.push_back(k);
        }
        for (auto k : odd_max_values) {
            max_values.push_back(k);
        }

        sort(all(max_values), greater<>());
        cout << odd_sum + even_sum - max_values[0] - max_values[1] << '\n';
    }
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << '\n';
        solution();
    }
}