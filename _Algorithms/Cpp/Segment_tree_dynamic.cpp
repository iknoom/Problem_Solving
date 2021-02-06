#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    struct Node {
        int l, r;
        long long val;
        Node() : l(-1), r(-1), val(0) { }
        Node(long long val) : l(-1), r(-1), val(val) { }
        Node(int l, int r, long long val) : l(l), r(r), val(val) { }
    };
    vector<Node> node;
    int L, R;
    SegTree(){ node.push_back(0); L = 1; R = 1000000000; }
    SegTree(int l, int r){ node.push_back(0); L = l; R = r; }

    void update(int i, int x) { update(i, x, 0, L, R); }
    void update(int i, int x, int nidx, int node_st, int node_ed) {
        if(i < node_st || i > node_ed) return;
        node[nidx].val += x;
        if(node_st != node_ed){
            int mid = (node_st + node_ed) / 2;
            if(i <= mid) {
                if(node[nidx].l < 0) {
                    node.push_back(0);
                    node[nidx].l = node.size() - 1;
                }
                update(i, x ,node[nidx].l, node_st, mid);
            }
            else{
                if(node[nidx].r < 0) {
                    node.push_back(0);
                    node[nidx].r = node.size() - 1;
                }
                update(i, x ,node[nidx].r, mid + 1, node_ed);
            }
        }
    }

    long long sum(int i, int j) { return sum(i, j, 0, L, R); }
    long long sum(int i, int j, int nidx, int node_st, int node_ed) {
        if(j < node_st || i > node_ed) return 0;
        else if(i <= node_st && node_ed <= j) return node[nidx].val;
        int mid = (node_st + node_ed) / 2;
        return sum(i, j, node[nidx].l, node_st, mid) + sum(i, j, node[nidx].r, mid + 1, node_ed);
    }

};

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    SegTree T(1, 1000000);
    int N, M, K;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        int val;
        cin >> val;
        T.update(i, val);
    }
    for(int i = 0; i < M + K; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            int tmp = T.sum(b, b);
            int diff = c - tmp;
            T.update(b, diff);
        }
        else{
          cout << T.sum(b, c) << endl;
        }
    }
}