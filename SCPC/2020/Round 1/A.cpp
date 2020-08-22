#include <bits/stdc++.h>
using namespace std;

int N, K, A[200001], B[200001];

int solution() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A, A + N);
    sort(B, B + N);

    int ret = 0;
    for (int i = 0; i < K; i++) {
        ret = max(ret, A[i] + B[K - i - 1]);
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int Answer = solution();
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    return 0;
}