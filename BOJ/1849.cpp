#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
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
    fastio;
    int N;
    cin >> N;
    SegTree segTree(N + 1);
    for (int i = 1; i <= N; i++) {
        segTree.arr[i + segTree.start] = 1;
    }
    segTree.prepare();
    vector<int> answer(N);
    for (int i = 0; i < N; i++) {
        int k, a;
        cin >> k;
        a = segTree.search(k + 1);
        answer[a - 1] = i + 1;
        segTree.update(a, 0);
    }
    for (auto k : answer) {
        cout << k << '\n';
    }
}