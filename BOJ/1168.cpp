#include <bits/stdc++.h>

using namespace std;

const int SIZE = 262144;
struct SegTree{
    int size, start;
    int arr[SIZE];

    SegTree(int n): size(n){
        start = 1;
        while (start < size) start *= 2;
        memset(arr, 0, sizeof(arr));
    }

    void prepare(){
        for(int i = start - 1; i; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
    }

    void update(int here, int val){
        here += start;
        arr[here] = val;
        while (here){
            here /= 2;
            arr[here] = arr[here * 2] + arr[here * 2 + 1];
        }
    }

    int search(int k) {
        int pos = 1;
        while(pos < start){
            if(k <= arr[pos << 1]) pos <<= 1;
            else k -= arr[pos << 1], pos = pos << 1 | 1;
        }
        return pos - start;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    SegTree T(N + 1);
    for (int i = 1; i <= N; i++){
        T.arr[T.start + i] = 1;
    }
    T.prepare();
    vector<int> answer;

    int cur_kth = 0;
    for (int i = 0; i < N; i++){
        cur_kth = (cur_kth + K - 1) % (N - i);
        int cur_i = T.search(cur_kth + 1);
        answer.push_back(cur_i);
        T.update(cur_i, 0);
    }
    cout << '<';
    for (int i = 0; i < (int)answer.size() - 1; i++) {
        cout << answer[i] << ", ";
    }
    cout << answer.back() << '>';
}