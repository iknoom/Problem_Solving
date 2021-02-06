#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
int N, K, Q, V[200005], cloneV[200005];
const int SIZE = 1048576;

int readInt() {
    int ret = 0;
    char now = getchar();

    while (now == 10 || now == 32) now = getchar();
    while (now >= 48 && now <= 57) {
        ret = ret * 10 + now - 48;
        now = getchar();
    }
    return ret;
}

struct SegTree{
    int size, start;
    int arr[SIZE];

    SegTree() {
        size = SIZE; start = SIZE / 2;
        memset(arr, 0, sizeof(arr));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int here, int val){
        here += start;
        arr[here] += val;
        while (here){
            here >>= 1;
            arr[here] = arr[here << 1] + arr[here << 1 | 1];
        }
    }

    int search(int k){
        int pos = 1;
        while(pos < start){
            if(k <= arr[pos << 1]) pos <<= 1;
            else k-=arr[pos << 1], pos = pos << 1 | 1;
        }
        return pos-start;
    }

};

int getidx(int x, vector<int> &idx){
    return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
}

void solution() {
    vector<int> idx;
    N = readInt();
    K = readInt();
    Q = readInt();
    for (int i = 0; i < N; i++) {
        V[i] = readInt();
        cloneV[i] = V[i];
    }

    // 모든 Ksum에 대해서 좌표압축 ========================================
    vector<int> Ksum;
    vector<int> clone;
    int S = 0;
    for (int i = 0; i < K; i++) S += V[i];
    Ksum.push_back(S);
    clone.push_back(S);
    idx.push_back(S);

    for (int i = K; i < N; i++) {
        S -= V[i - K];
        S += V[i];
        Ksum.push_back(S);
        clone.push_back(S);
        idx.push_back(S);
    }
    // 쿼리 후 Ksum
    int diff;
    vector<pi> query;
    for (int loop = 0; loop < Q; loop++) {
        int a, b;
        a = readInt();
        b = readInt();;
        a--;
        query.emplace_back(a, b);

        diff = b - cloneV[a];
        for (int i = max(0, a - K + 1); i < min(a + 1, (int)clone.size()); i++) {
            clone[i] += diff;
            idx.push_back(clone[i]);
        }
        cloneV[a] = b;
    }

    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());

    // 좌표 압축 끝, 세그트리 준비 ===================================
    SegTree Seg;
    for (auto q : Ksum) {
        Seg.arr[Seg.start + getidx(q, idx)]++;
    }
    Seg.prepare();

    // 세그트리 쿼리 시작
    int a, b;
    int mid = ((int)Ksum.size() >> 1) + 1;
    printf("%d ", idx[Seg.search(mid)]);
    for (auto qy : query) {
        a = qy.first; b = qy.second;
        diff = b - V[a];
        for (int i = max(0, a - K + 1); i < min(a + 1, (int)Ksum.size()); i++) {
            Seg.update(getidx(Ksum[i], idx), -1);
            Ksum[i] += diff;
            Seg.update(getidx(Ksum[i], idx), 1);
        }
        V[a] = b;
        printf("%d ", idx[Seg.search(mid)]);
    }
    printf("\n");
}

int main() {
    int T, test_case;
    T = readInt();
    for(test_case = 0; test_case  < T; test_case++)
    {
        printf("Case #%d\n", test_case+1);
        solution();
    }
    return 0;
}