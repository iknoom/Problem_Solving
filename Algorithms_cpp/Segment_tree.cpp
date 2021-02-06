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
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int here, long long val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = arr[here * 2] + arr[here * 2 + 1];
        }
    }

    long long sum(int l, int r){
        l += start;
        r += start;
        long long ret = 0;
        while (l <= r){
            if (l % 2 == 1) ret += arr[l++];
            if (r % 2 == 0) ret += arr[r--];
            l /= 2; r /= 2;
        }
        return ret;
    }

    int search(int k) {
        int pos = 1;
        while(pos < start){
            if(k <= arr[pos << 1]) pos <<= 1;
            else k-=arr[pos << 1], pos = pos << 1 | 1;
        }
        return pos-start;
    }
};


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    SegTree T(N);
    for (int i = 0; i < N; i++){
        cin >> T.arr[T.start + i];
    }
    T.prepare();

    for (int i = 0; i < M + K; i++){
        int a; cin >> a;
        if (a == 1){
            int b; long long c;
            cin >> b >> c;
            T.update(b - 1, c);
        }
        else{
            int b, c; cin >> b >> c;
            cout << T.sum(b - 1, c - 1) << '\n';
        }
    }
}