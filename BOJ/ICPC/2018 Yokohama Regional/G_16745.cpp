#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
const int SIZE = 262144;

struct MergesortTree{
    vector<int> arr[SIZE];

    void construct(){
        for(int i = SIZE/2-1; i > 0; --i){
            vector<int> &c = arr[i], &l = arr[i*2], &r = arr[i*2+1];
            arr[i].resize(l.size()+r.size());
            for(int j = 0, p = 0, q = 0; j < c.size(); ++j){
                if(q == r.size() || (p < l.size() && l[p] < r[q])) c[j] = l[p++];
                else c[j] = r[q++];
            }
        }
    }

    int greater(int s, int e, int k, int node = 1, int ns = 0, int ne = SIZE/2){
        if(ne <= s || e <= ns) return 0;
        if(s <= ns && ne <= e)
            return arr[node].end() - upper_bound(arr[node].begin(), arr[node].end(), k);
        int mid = (ns+ne)/2;
        return greater(s, e, k, node*2, ns, mid) + greater(s, e, k, node*2+1, mid, ne);
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    MergesortTree Seg;
    vector<pi> A;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Seg.arr[SIZE / 2 + i].push_back(val);
        A.emplace_back(val, i);
    }

    Seg.construct();
    sort(A.begin(), A.end());

    long long ans = 0;
    for (auto p : A) {
        int val = p.first, i = p.second;
        ans += min(Seg.greater(0, i, val), Seg.greater(i, n, val));
    }
    cout << ans << '\n';
}