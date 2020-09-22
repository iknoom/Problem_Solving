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

    void propagate(int node, int s, int e){
        if(lazy[node]){
            if (node < start){
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            if (lazy[node] % 2) {
                arr[node] = (e - s + 1) - arr[node];
            }
            lazy[node] = 0;
        }
    }
    void update(int l, int r){ update(l, r, 1, 0, start - 1);}
    void update(int l, int r, int node, int s, int e){
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node]++;
            propagate(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(l, r, node * 2, s, mid);
        update(l, r, node * 2 + 1, mid + 1, e);
        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }

    int query(int l, int r){ return query(l, r, 1, 0, start - 1);}
    int query(int l, int r, int node, int s, int e){
        propagate(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r)  return arr[node];
        int mid = (s + e) / 2;
        return query(l, r, node * 2, s, mid) + query(l, r, node * 2 + 1, mid + 1, e);
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    SegLazy T(N);

    while (M--) {
        int a; cin >> a;
        if (a == 0){
            int l, r, k;
            cin >> l >> r;
            T.update(l - 1, r - 1);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << T.query(l - 1, r - 1) << '\n';
        }
    }
}