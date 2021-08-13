#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("adjustment.in", "r", stdin);
    freopen("adjustment.out", "w", stdout);
    long long n, q, col_sum = 0, row_sum = 0, col_cnt = 0, row_cnt = 0;
    cin >> n >> q;
    vector<bool> col_vst(n + 1, false), row_vst(n + 1, false);
    while (q--) {
        char c; long long x;
        cin >> c >> x;
        long long cur = n * x + (n * (n + 1) / 2);
        if (c == 'R') {
            if (row_vst[x]) {
                cout << 0 << '\n';
                continue;
            }
            cur -= x * col_cnt;
            cur -= col_sum;
            cout << cur << '\n';
            row_vst[x] = true;
            row_cnt++;
            row_sum += x;
        } else {
            if (col_vst[x]) {
                cout << 0 << '\n';
                continue;
            }
            cur -= x * row_cnt;
            cur -= row_sum;
            cout << cur << '\n';
            col_vst[x] = true;
            col_cnt++;
            col_sum += x;
        }
    }
}