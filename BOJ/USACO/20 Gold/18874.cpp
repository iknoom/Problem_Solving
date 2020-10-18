#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2097152;
using pi = pair<int, int>;
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
};


int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    SegTree T(N);

    vector<pi> v(N);
    for (int i = 0; i < N; i++){
        T.arr[T.start + i]++;
        cin >> v[i].first;
        v[i].second = i;
    }
    T.prepare();
    sort(v.begin(), v.end());


    long long cur = 0;
    int idx = 0;
    for (int i = 0; i < N; i++) {
        cout << cur << '\n';
        vector<int> tmp;
        while (idx < N && v[idx].first == i) {
            T.update(v[idx].second, 0);
            tmp.push_back(v[idx].second);
            idx++;
        }
        for (auto k : tmp) {
            cur += T.sum(0, k);
        }
    }
}