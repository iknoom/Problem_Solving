#include <bits/stdc++.h>
using namespace std;

const int SIZE = 2097152;

using pi = pair<int, int>;

struct query{
    int a, b, k;
    long long v;
    query() : a(0), b(0), v(0), k(0) { }
};

struct SegTree{
    int size, start;
    long long arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1]; // val
    }

    void update(int here, long long val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = arr[here * 2] + arr[here * 2 + 1];             // val
        }
    }

    long long sum(int l, int r){
        l += start;
        r += start;
        long long ret = 0;
        while (l <= r){
            if (l % 2 == 1) ret += arr[l++];                            // val
            if (r % 2 == 0) ret += arr[r--];                            // val
            l /= 2; r /= 2;
        }
        return ret;
    }
};


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    SegTree T(N);
    for (int i = 0; i < N; i++){
        cin >> T.arr[T.start + i];
    }
    T.prepare();

    int M;
    cin >> M;
    vector<query> q1;
    vector<query> q2;
    vector<long long> ans;
    vector<pi> q2_stack;

    for (int i = 0; i < M; i++){
        query tmp;
        int a; cin >> a;
        if (a == 1){
            cin >> tmp.a >> tmp.v;
            q1.push_back(tmp);
        }
        else{
            cin >> tmp.k >> tmp.a >> tmp.b;
            q2.push_back(tmp);
            q2_stack.push_back({tmp.k, q2.size() - 1});
        }
    }
    ans.resize(q2.size());
    sort(q2_stack.begin(), q2_stack.end(), greater<pi>());

    int cnt = 0;
    for (auto query1 : q1){
        while (!q2_stack.empty() && q2_stack.back().first == cnt){
            int idx = q2_stack.back().second;
            q2_stack.pop_back();
            ans[idx] = T.sum(q2[idx].a - 1, q2[idx].b - 1);
        }
        cnt++;
        T.update(query1.a - 1, query1.v);
    }
    while (!q2_stack.empty() && q2_stack.back().first == cnt){
        int idx = q2_stack.back().second;
        q2_stack.pop_back();
        ans[idx] = T.sum(q2[idx].a - 1, q2[idx].b - 1);
    }

    for (auto k : ans){
        cout << k << '\n';
    }
}