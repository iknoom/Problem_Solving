#include <bits/stdc++.h>

#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
const int SIZE = 262144;
const int INF = 1e9;

struct SegTree{
    int size, start;
    int dist[SIZE], price[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        fill(dist, dist + start * 2, 0);
        fill(price, price + start * 2, INF);
    }

    void prepare(){
        for(int i = start - 1; i; i--) {
            dist[i] = dist[i * 2] + dist[i * 2 + 1];
            price[i] = min(price[i * 2], price[i * 2 + 1]);
        }
    }

    void update_dist(int here, int val){
        here += start;
        dist[here] = val;
        while (here){
            here /= 2;
            dist[here] = dist[here * 2] + dist[here * 2 + 1];
        }
    }

    int query(int x, int m) {
        int _l, _r, l, r;
        l = x;
        r = x;
        // left range
        if (x > 0) {
            _l = 0;
            _r = size;
            while (_l + 1 < _r) {
                int mid = (_l + _r) / 2;
                if (x - mid < 0) {
                    _r = mid;
                    continue;
                }
                if (_sum_dist(x - mid, x - 1) <= m) {
                    _l = mid;
                } else {
                    _r = mid;
                }
            }
            l = x - _l;
        }
        // right range
        if (x < size - 1) {
            _l = 0;
            _r = size;
            while (_l + 1 < _r) {
                int mid = (_l + _r) / 2;
                if (x - 1 + mid >= size) {
                    _r = mid;
                    continue;
                }
                if (_sum_dist(x, x - 1 + mid) <= m) {
                    _l = mid;
                } else {
                    _r = mid;
                }
            }
            r = x + _l;
        }
        return _min_price(l, r);
    }

    int _sum_dist(int l, int r){
        l += start;
        r += start;
        int ret = 0;
        while (l <= r){
            if (l % 2 == 1) ret += dist[l++];
            if (r % 2 == 0) ret += dist[r--];
            l /= 2; r /= 2;
        }
        return ret;
    }

    int _min_price(int l, int r){
        l += start;
        r += start;
        int ret = INF;
        while (l <= r){
            if (l % 2 == 1) ret = min(ret, price[l++]);
            if (r % 2 == 0) ret = min(ret, price[r--]);
            l /= 2; r /= 2;
        }
        return ret;
    }
};

int main() {
    fastio;
    // input
    int N;
    cin >> N;
    SegTree tree(N);
    for (int i = 0; i < N; i++){
        cin >> tree.price[tree.start + i];
    }
    for (int i = 0; i < N - 1; i++){
        cin >> tree.dist[tree.start + i];
    }
    tree.dist[tree.start + N - 1] = 0;
    // query
    tree.prepare();
    int Q;
    cin >> Q;
    while (Q--) {
        string query;
        cin >> query;
        if (query == "CALL") {
            int x, m;
            cin >> x >> m;
            cout << tree.query(x - 1, m) << '\n';
        } else if (query == "UPDATE") {
            int x, t;
            cin >> x >> t;
            tree.update_dist(x - 1, t);
        }
    }
}