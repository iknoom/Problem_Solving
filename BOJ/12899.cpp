#include <bits/stdc++.h>
using namespace std;

const int SIZE = 4194304;

struct SegTree{
    int size, start;
    int arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }

    void update(int here, int val){
        here += start;
        arr[here] += val;
        while (here){
            here /= 2;
            arr[here] = arr[here * 2] + arr[here * 2 + 1];
        }
    }

    int query(int idx, int k){
        if (idx >= start)
            return idx - start;
        else if (arr[idx << 1] >= k)
            return query(idx << 1, k);
        else
            return query(idx << 1 | 1, k - arr[idx << 1]);
    }
};


int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    SegTree T(2000001);
    while (N--){
        int type, X;
        cin >> type >> X;
        if (type == 1){
            T.update(X, 1);
        }
        else {
            int ans = T.query(1, X);
            cout << ans << '\n';
            T.update(ans, -1);
        }
    }
}