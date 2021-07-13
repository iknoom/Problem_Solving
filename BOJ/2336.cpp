#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

const int SIZE = 2097152;

struct SegTree{
    int size, start;
    int arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        fill(arr, arr + SIZE, INF);
    }

    void update(int here, int val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = min(arr[here * 2], arr[here * 2 + 1]);
        }
    }

    int get_min(int l, int r){
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

int main() {
    fastio;
    int N;
    cin >> N;
    vector<int> A(N), B_idx(N), C_idx(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < N; i++) {
        int u;
        cin >> u;
        u--;
        B_idx[u] = i;
    }
    for (int i = 0; i < N; i++) {
        int u;
        cin >> u;
        u--;
        C_idx[u] = i;
    }
    SegTree segTree(N + 1);
    int answer = 0;
    for (int u : A) {
        // C_idx[u]까지의 최솟값
        int min_idx = segTree.get_min(0, C_idx[u]);
        if (min_idx > B_idx[u]) {
            answer++;
        }
        // 최솟값 갱신
        segTree.update(C_idx[u], B_idx[u]);
    }
    cout << answer << '\n';
}