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
    int N, K;
    long long ans = 0;
    cin >> N >> K;
    SegTree T(65536);
    vector<int> tmp;

    for (int i = 0; i < K - 1; i++){
        int X;
        cin >> X;
        tmp.push_back(X);
        T.update(X, 1);
    }
    for (int i = 0; i < N - K + 1; i++){
        int X;
        cin >> X;
        tmp.push_back(X);
        T.update(X, 1);
        ans += T.query(1, (K + 1)/2);
        T.update(tmp[i], -1);
    }
    cout << ans << endl;
}