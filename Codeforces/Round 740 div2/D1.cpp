#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int SIZE = 2097152;
int n, m;

struct SegTree{
    int size, start;
    long long arr[SIZE * 2];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }

    long long get(int here){
        here += start;
        long long ret = arr[here];
        while (here){
            here /= 2;
            ret += arr[here];
            ret %= m;
        }
        return ret;
    }

    long long update(int l, int r, long long val){
        l += start;
        r += start;
        while (l <= r){
            if (l % 2 == 1) {
                arr[l] += val;
                arr[l] %= m;
                l++;
            }
            if (r % 2 == 0) {
                arr[r] += val;
                arr[r] %= m;
                r--;
            }
            l /= 2; r /= 2;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    SegTree segTree(n + 1);
    segTree.arr[segTree.start + n] = 1;
    for (int i = n; i > 1; i--) {
        long long cur = segTree.get(i);
        segTree.update(1, i - 1, cur);
        long long l = i;
        while (l > 1) {
            int idx = i / l;
            int nxt_idx = idx + 1;
            long long r = i / nxt_idx;
            segTree.update(idx, idx, (l - r) * cur % m);
            l = r;
        }
    }
    cout << segTree.get(1) << '\n';
}