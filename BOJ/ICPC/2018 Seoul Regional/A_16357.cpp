#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using pii = tuple<int, int, int>;
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
            arr[node] += lazy[node];
            lazy[node] = 0;
        }
    }
    void update(int l, int r, int inc){ update(l, r, inc, 1, 0, start - 1);}
    void update(int l, int r, int inc, int node, int s, int e){
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
        arr[node] = max(arr[node * 2], arr[node * 2 + 1]);
    }

    int query(int l, int r){ return query(l, r, 1, 0, start - 1);}
    int query(int l, int r, int node, int s, int e){
        propagate(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r)  return arr[node];
        int mid = (s + e) / 2;
        return max(query(l, r, node * 2, s, mid), query(l, r, node * 2 + 1, mid + 1, e));
    }
};

vector<int> idx;

int getidx(int x){
    return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    SegLazy T(2*N);
    vector<pi> intervals;
    for (int i = 0; i < N; i++) {
        int ux, uy, vx, vy;
        cin >> ux >> uy >> vx >> vy;
        idx.push_back(uy);
        idx.push_back(vy);
        intervals.emplace_back(vy, uy);
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());

    vector<pii> sweeping;
    for (int i = 0; i < N; i++) {
        int a, b;
        a = getidx(intervals[i].first);
        b = getidx(intervals[i].second);
        sweeping.emplace_back(a, -1, b);
        sweeping.emplace_back(b, 1, a);
        T.update(a, b, 1);
    }
    sort(sweeping.begin(), sweeping.end());

    int cur = 0, ans = 0;
    for (auto tp : sweeping) {
        int a, t, b;
        tie(a, t, b) = tp;
        cur -= t;
        if (t < 0) T.update(a, b, -1);
        else T.update(b, a, 1);
        ans = max(ans, cur + T.query(0, 2*N));
    }

    cout << ans << '\n';
}