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
        for(int i = start - 1; i; i--) arr[i] = max(arr[i * 2], arr[i * 2 + 1]); // val
    }

    void update(int here, pi val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = max(arr[here * 2], arr[here * 2 + 1]);             // val
        }
    }

    pi query(int l, int r){
        if (l > r) return {-1, -1};
        l += start;
        r += start;
        pi ret = {-1, -1};
        while (l <= r){
            if (l % 2 == 1) ret = max(ret, arr[l++]);                            // val
            if (r % 2 == 0) ret = max(ret, arr[r--]);                            // val
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
        cin >> T.arr[T.start + i].first;
        T.arr[T.start + i].second = i;
    }
    T.prepare();

    int M;
    cin >> M;
    for (int i = 0; i < M; i++){
        int a; cin >> a;
        if (a == 1){
            int b; int c;
            cin >> b >> c;
            T.update(b - 1, {c, b - 1});
        }
        else{
            int b, c; cin >> b >> c;
            b--; c--;
            pi mid = T.query(b, c);
            pi R = T.query(mid.second + 1, c);
            pi L = T.query(b, mid.second - 1);
            cout << mid.first + max(R.first, L.first) << '\n';
        }
    }
}