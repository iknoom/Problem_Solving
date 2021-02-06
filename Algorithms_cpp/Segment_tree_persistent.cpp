#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

struct PST {
    struct Node {
        int l, r;
        long long val;
        Node() : l(-1), r(-1), val(0) { }
        Node(long long val) : l(-1), r(-1), val(val) { }
        Node(int l, int r, long long val) : l(l), r(r), val(val) { }
    };
    int L, R;
    vector<Node> node;
    vector<int> head;

    PST(int l, int r) : L(l), R(r){
        node.push_back(0);
        head.push_back(0);
        init(0, 1, 100001);
    }

    void init(int nidx, int node_st, int node_ed){
        if (node_st == node_ed) return;
        int mid = (node_st + node_ed) / 2;

        node.push_back(0);
        node[nidx].l = node.size() - 1;
        init(node[nidx].l, node_st, mid);

        node.push_back(0);
        node[nidx].r = node.size() - 1;
        init(node[nidx].r, mid + 1, node_ed);
    }

    void add_head(){
        node.push_back({node[head.back()].l, node[head.back()].r, node[head.back()].val});
        head.push_back(node.size() - 1);
    }

    void add(int x, int i, int diff) {
        node[head[i]].val += diff;
        _add(i, diff, head[x], L, R);
    }
    void _add(int i, int diff, int nidx, int node_st, int node_ed) {
        if (node_st == node_ed) return;
        int mid = (node_st + node_ed) / 2;
        if (i <= mid) {
            int lidx = node[nidx].l;
            node.push_back({node[lidx].l, node[lidx].r, node[lidx].val + diff});
            node[nidx].l = node.size() - 1;
            _add(i, diff, node[nidx].l, node_st, mid);
        }
        else {
            int ridx = node[nidx].r;
            node.push_back({node[ridx].l, node[ridx].r, node[ridx].val + diff});
            node[nidx].r = node.size() - 1;
            _add(i, diff, node[nidx].r, mid + 1, node_ed);
        }
    }

    long long sum(int x, int i, int j) { return _sum(i, j, head[x], L, R); }
    long long _sum(int i, int j, int nidx, int node_st, int node_ed){
        if (j < node_st || node_ed < i) return 0;
        if (i <= node_st && node_ed <= j) return node[nidx].val;
        int mid = (node_st + node_ed) / 2;
        return _sum(i, j, node[nidx].l, node_st, mid) + _sum(i, j, node[nidx].r, mid + 1, node_ed);
    }
};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--){
        PST tree(0, 100000);
        vector<int> yi[100001];
        int N, M;

        cin >> N >> M;
        while (N--){
            int x, y; cin >> x >> y;
            yi[x].push_back(y);
        }

        for (int i = 1; i <= 100001; i++){
            if (tree.head.size() < i + 1){
                tree.add_head();
            }
            for (auto y : yi[i - 1]){
                tree.add(i, y, 1);
            }
        }

        long long ans = 0;
        while (M--) {
            int l, r, b, t;
            cin >> l >> r >> b >> t;
            ans += tree.sum(r + 1, b, t) - tree.sum(l, b, t);
        }
        cout << ans << endl;
    }
}