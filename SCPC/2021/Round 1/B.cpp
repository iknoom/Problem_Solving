#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

void solution() {
    int n, t;
    cin >> n >> t;
    string b_str;
    cin >> b_str;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        bool zero_flag = false;
        int cnt = 0;
        if (i + t < n) {
            if (b_str[i + t] == '0') {
                zero_flag = true;
            }
            cnt++;
        }
        if (i - t >= 0) {
            if (b_str[i - t] == '0') {
                zero_flag = true;
            }
            cnt++;
        }
        if (!zero_flag && cnt > 0) {
            a[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        if (i < t) {
            if (i + t * 2 < n && a[i + t * 2] == 1) {
                a[i] = 0;
            }
        }
        else if (n - t <= i) {
            if (i - t * 2 >= 0 && a[i - t * 2] == 1) {
                a[i] = 0;
            }
        }
        else {
            int one_cnt = 0;
            if (i + t * 2 < n && a[i + t * 2] == 1) {
                one_cnt++;
            }
            if (i - t * 2 >= 0 && a[i - t * 2] == 1) {
                one_cnt++;
            }
            if (one_cnt == 2) {
                a[i] = 0;
            }
        }
    }
    for (int k : a) {
        cout << k;
    }
    cout << '\n';
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