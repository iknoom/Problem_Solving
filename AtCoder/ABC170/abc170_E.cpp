#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAX_SIZE = 200002;
const int INF = 1e9+4;
const int SIZE = 2097152;

struct SegTree{
    int size, start;
    int arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        fill(arr, arr+SIZE, INF);
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
    }

    void update(int here, long long val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = min(arr[here * 2], arr[here * 2 + 1]);
        }
    }

    int query(int l, int r){
        l += start;
        r += start;
        int ret = INF;
        while (l <= r){
            if (l % 2 == 1) ret = min(ret, arr[l++]);
            if (r % 2 == 0) ret = min(ret, arr[r--]);
            l /= 2; r /= 2;
        }
        return ret;
    }
};

set<pi> kindergartens[MAX_SIZE];
int rating[MAX_SIZE], belong[MAX_SIZE];



int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N, Q;
    SegTree T(MAX_SIZE);

    cin >> N >> Q;
    for (int i = 0; i < N; i++){
        cin >> rating[i] >> belong[i];
        kindergartens[belong[i]].insert({rating[i], i});
        if (T.arr[T.start + belong[i]] == INF){
            T.arr[T.start + belong[i]] = rating[i];
        } else {
            T.arr[T.start + belong[i]] = max(T.arr[T.start + belong[i]], rating[i]);
        }
    }
    T.prepare();

    for (int i = 0; i < Q; i++){
        int C, D;
        cin >> C >> D;
        C--;
        kindergartens[belong[C]].erase({rating[C], C});
        if (!kindergartens[belong[C]].empty())
            T.update(belong[C], kindergartens[belong[C]].rbegin()->first);
        else
            T.update(belong[C], INF);
        belong[C] = D;
        kindergartens[belong[C]].insert({rating[C], C});
        T.update(belong[C], kindergartens[belong[C]].rbegin()->first);
        cout << T.query(0, MAX_SIZE) << '\n';
    }
}
