#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

const int SIZE = 262144;

struct SegTree{
    int size, start;
    long long arr[SIZE];
    int coef[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start <<= 1;
        memset(arr, 0, sizeof(arr));
        memset(coef, 0, sizeof(coef));
    }

    long long get_star(int here){
        int i = here + start, l = here, interval = 1;
        long long ret = arr[i] + coef[i];
        while (i){
            if (i & 1) {
                l -= interval;
            }
            i >>= 1;
            interval <<= 1;
            ret += arr[i];
            ret += (long long)coef[i] * (here - l + 1);
        }
        return ret;
    }

    void query(int l, int r){
        int interval = 1, a = 1, b = r - l + 1;
        l += start;
        r += start;
        while (l <= r){
            if (l & 1) {
                // [a, a + interval - 1]
                coef[l]++;
                arr[l] += a - 1;
                a += interval;
                l++;
            }
            if (!(r & 1)){
                // [b - interval + 1, b]
                coef[r]++;
                arr[r] += b - interval;
                b -= interval;
                r--;
            }
            l >>= 1; r >>= 1; interval <<= 1;
        }
    }
};

int main() {
    fastio;
    int N;
    cin >> N;
    SegTree segTree(N + 1);
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) cin >> arr[i];

    int Q;
    cin >> Q;
    while (Q--) {
        int t, i, l, r;
        cin >> t;
        if (t == 1) {
            cin >> l >> r;
            segTree.query(l, r);
        } else {
            cin >> i;
            cout << segTree.get_star(i) + arr[i]<< '\n';
        }
    }
}