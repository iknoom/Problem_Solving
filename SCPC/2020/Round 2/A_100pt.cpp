#include <bits/stdc++.h>
using namespace std;

int N, K;
long long A[200001], B[200001];

long long solution() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A, A + N);
    sort(B, B + N);

    long long right_sum = 0, left_sum = 0, sft_sum = 0, sum = abs(A[0] - B[0]);
    for (int i = 1; i < N; i++) {
        sft_sum = min(sum, min(min(sft_sum, left_sum), right_sum) + abs(A[i] - B[i]));
        right_sum = min(sum, right_sum + abs(A[i - 1] - B[i]));
        left_sum = min(sum, left_sum + abs(A[i] - B[i - 1]));
        sum += abs(A[i] - B[i]);
    }
    return min(min(sft_sum, left_sum), right_sum);
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        long long Answer = solution();
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }
    return 0;
}