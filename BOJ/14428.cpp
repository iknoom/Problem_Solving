#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2097152;
using pi = pair<int, int>;

struct SegTree{
    int size, start;
    pi arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = min(arr[i * 2], arr[i * 2 + 1]); // val
    }

    void update(int here, pi val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = min(arr[here * 2], arr[here * 2 + 1]);             // val
        }
    }

    pi query(int l, int r){
        l += start;
        r += start;
        pi ret = {1e9, 1e9};
        while (l <= r){
            if (l % 2 == 1) ret = min(ret, arr[l++]);                            // val
            if (r % 2 == 0) ret = min(ret, arr[r--]);                            // val
            l /= 2; r /= 2;
        }
        return ret;
    }
};


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    SegTree T(N);
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        T.arr[T.start + i] = {a, i};
    }
    T.prepare();


    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++){
        int a; cin >> a;
        if (a == 1){
            int b; int c;
            cin >> b >> c;
            T.update(b - 1, {c, b - 1});
        }
        else {
            int b, c;
            cin >> b >> c;
            pi ret = T.query(b - 1, c - 1);
            cout << ret.second + 1 << '\n';
        }
    }
}