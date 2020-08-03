#include <bits/stdc++.h>

using namespace std;
const int MAX = 500005;
const int MAX_V = 500005;

int sqrtN;
int N, M, A[MAX], result[MAX], cnt[MAX_V];

struct QueryNode{
    int s, e, n;
    QueryNode(): QueryNode(0, 0, -1) { }
    QueryNode(int s1, int e1, int n1): s(s1), e(e1), n(n1) { }
    bool operator <(const QueryNode &Q)const{
        if(s/sqrtN != Q.s / sqrtN) return (s / sqrtN < Q.s / sqrtN);
        return (e < Q.e);
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    sqrtN = sqrt(N);

    QueryNode Q[MAX];
    for(int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        Q[i] = QueryNode(l-1, r, i);
    }
    sort(Q, Q+M);


    int dcnt = 0;
    int s = Q[0].s, e = Q[0].e;
    for(int i = s; i < e; i++)
        if(cnt[A[i]] == 0){
            cnt[A[i]]++;
            dcnt++;
        }
    result[Q[0].n] = dcnt;


    for(int i = 1; i < M; ++i) {
        while(Q[i].s < s) if(cnt[A[--s]]++ == 0) ++dcnt;
        while(e < Q[i].e) if(cnt[A[e++]]++ == 0) ++dcnt;
        while(Q[i].s > s) if(--cnt[A[s++]] == 0) --dcnt;
        while(e > Q[i].e) if(--cnt[A[--e]] == 0) --dcnt;
        result[Q[i].n] = dcnt;
    }

    for(int i = 0; i < M; ++i)
        cout << result[i] << '\n';

}