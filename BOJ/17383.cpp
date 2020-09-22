#include <bits/stdc++.h>

using namespace std;
int N, T[100001];

bool determine(int K) {
    if (N == 1) {
        return T[0] <= K;
    }
    int A, B;
    A = 0; B = 0;
    int i, j;
    i = 0;
    j = N - 1;
    while (i < j) {
        if (A <= B) {
            if (abs(A - B) <= 1) {
                A += (T[j--] + K - 1) / K;
            } else {
                if ((T[i] + K - 1) / K > 1) return false;
                A++; i++;
            }
        } else {
            if (abs(A - B) <= 1) {
                B += (T[j--] + K - 1) / K;
            } else {
                if ((T[i] + K - 1) / K > 1) return false;
                B++; i++;
            }
        }
    }
    return abs(A - B) <= 1;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    sort(T, T + N);
    int L, R;
    L = 0; R = 1000000005;
    while (L + 1 < R) {
        int mid = (L + R) / 2;
        if (determine(mid)) R = mid;
        else L = mid;
    }

    cout << R << '\n';
}