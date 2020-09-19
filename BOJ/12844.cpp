#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2097152;

struct SegLazy{
    int size, start;
    int arr[SIZE], lazy[SIZE];

    SegLazy(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
        memset(lazy, 0, sizeof(lazy));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] ^ arr[i * 2 + 1];
    }

    void propagate(int node, int s, int e){
        if(lazy[node]){
            if (node < start){
                lazy[node * 2] ^= lazy[node];
                lazy[node * 2 + 1] ^= lazy[node];
            }
            if ((e - s + 1) % 2) {
                arr[node] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void update(int l, int r, int inc){ update(l, r, inc, 1, 0, start - 1);}
    void update(int l, int r, int inc, int node, int s, int e){
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] ^= inc;
            propagate(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(l, r, inc, node * 2, s, mid);
        update(l, r, inc, node * 2 + 1, mid + 1, e);
        arr[node] = arr[node * 2] ^ arr[node * 2 + 1];
    }

    int query(int l, int r){ return query(l, r, 1, 0, start - 1);}
    int query(int l, int r, int node, int s, int e){
        propagate(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r)  return arr[node];
        int mid = (s + e) / 2;
        return query(l, r, node * 2, s, mid) ^ query(l, r, node * 2 + 1, mid + 1, e);
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    SegLazy T(N);
    for (int i = 0; i < N; i++){
        cin >> T.arr[T.start + i];
    }
    T.prepare();
    int Q;
    cin >> Q;
    while (Q--) {
        int a; cin >> a;
        if (a == 1){
            int l, r, k;
            cin >> l >> r >> k;
            T.update(l, r, k);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << T.query(l, r) << '\n';
        }
    }
}