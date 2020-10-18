#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2097152;
vector<int> adj[100001];
int cnt, l[100001], r[100001];

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
        if (lazy[node] != 0){
            if (node < start){
                lazy[node * 2] = lazy[node];
                lazy[node * 2 + 1] = lazy[node];
            }
            if (lazy[node] > 0) arr[node] = (e - s + 1);
            else if(lazy[node] < 0) arr[node] = 0;
            lazy[node] = 0;
        }
    }
    void update(int l, int r, long long inc){ update(l, r, inc, 1, 0, start - 1);}
    void update(int l, int r, long long inc, int node, int s, int e){
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] = inc;
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

int dfs(int u) {
    int max_r;
    max_r = l[u] = cnt++;
    for (auto v : adj[u]) {
        max_r = max(max_r, dfs(v));
    }
    r[u] = max_r;
    return max_r;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N;
    for (int u = 0; u < N; u++) {
        int v;
        cin >> v;
        v--;
        if (v < 0) continue;
        adj[v].push_back(u);
    }
    fill(l, l + N, -1);
    for (int i = 0; i < N; i++) {
        if (l[i] < 0) {
            dfs(i);
        }
    }
//
//    for (int i = 0; i < N; i++) {
//        cout << l[i] << ' ';
//    }
//    cout << endl;
//    for (int i = 0; i < N; i++) {
//        cout << r[i] << ' ';
//    }
//    cout << endl;


    SegLazy T(N);
    for (int i = 0; i < N; i++){
        T.arr[T.start + i]++;
    }
    T.prepare();
    cin >> M;

    while (M--) {
        int t, i;
        cin >> t >> i;
        i--;
        if (t == 1) {
            if (l[i] == r[i]) continue;
            T.update(l[i] + 1, r[i], 1);
        } else if (t == 2) {
            if (l[i] == r[i]) continue;
            T.update(l[i] + 1, r[i], -1);
        } else {
            if (l[i] == r[i]) cout << 0 << '\n';
            else cout << T.sum(l[i] + 1, r[i]) << '\n';
        }
    }
}