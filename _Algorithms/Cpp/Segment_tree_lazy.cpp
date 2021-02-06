#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2097152;

struct SegLazy{
    int size, start;
    long long arr[SIZE], lazy[SIZE];

    SegLazy(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
        memset(lazy, 0, sizeof(lazy));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void propagate(int node, int s, int e){
        if(lazy[node]){
            if (node < start){
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            arr[node] += lazy[node] * (e - s + 1);
            lazy[node] = 0;
        }
    }
    void update(int l, int r, long long inc){ update(l, r, inc, 1, 0, start - 1);}
    void update(int l, int r, long long inc, int node, int s, int e){
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] += inc;
            propagate(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(l, r, inc, node * 2, s, mid);
        update(l, r, inc, node * 2 + 1, mid + 1, e);
        arr[node] = arr[node * 2] + arr[node * 2 + 1];
    }

    long long sum(int l, int r){ return sum(l, r, 1, 0, start - 1);}
    long long sum(int l, int r, int node, int s, int e){
        propagate(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r)  return arr[node];
        int mid = (s + e) / 2;
        return sum(l, r, node * 2, s, mid) + sum(l, r, node * 2 + 1, mid + 1, e);
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    SegLazy T(N);
    for (int i = 0; i < N; i++){
        cin >> T.arr[T.start + i];
    }
    T.prepare();

    for (int i = 0; i < M + K; i++){
        int a; cin >> a;
        if (a == 1){
            int b, c, d;
            cin >> b >> c >> d;
            T.update(b - 1, c - 1, d);
        }
        else{
            int b, c, d;
            cin >> b >> c;
            cout << T.sum(b - 1, c - 1) << '\n';
        }
    }
}