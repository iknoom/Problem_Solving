#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2097152;

struct SegTree{
    int size, start;
    long long arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1]; // val
    }

    void update(int here, long long val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = arr[here * 2] + arr[here * 2 + 1];             // val
        }
    }

    long long sum(int l, int r){
        if (l > r){
            swap(l, r);
        }
        l += start;
        r += start;
        long long ret = 0;
        while (l <= r){
            if (l % 2 == 1) ret += arr[l++];                            // val
            if (r % 2 == 0) ret += arr[r--];                            // val
            l /= 2; r /= 2;
        }
        return ret;
    }
};


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    SegTree T(N);
    for (int i = 0; i < N; i++){
        cin >> T.arr[T.start + i];
    }
    T.prepare();

    while (Q--) {
        int a, b, c;
        long long d;
        cin >> a >> b >> c >> d;
        cout << T.sum(a - 1, b - 1) << '\n';
        T.update(c - 1, d);
    }
}