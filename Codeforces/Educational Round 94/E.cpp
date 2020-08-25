#include <bits/stdc++.h>

using namespace std;
int N, A[5003];

int solution(int i, int j) {
    while (i < j && A[i] == 0) i += 1;
    while (i <= j && A[j] == 0) j -= 1;
    if (i > j) return 0;
    int ret = 1e9;
    int H = 0;
    while (true) {
        int S = 0;
        int min_h = 1e9;
        // k in range(i, j + 1):
        for (int k = i; k <= j; k++){
            if (A[k] != 0) S++;
            min_h = min(min_h, A[k]);
        }
        ret = min(ret, H + S);

        if (S == 0) break;

        if (j - i + 1 == S){
            //for k in range(i, j + 1):
            for (int k = i; k <= j; k++) {
                A[k] -= min_h;
            }
            H += min_h;
        }
        else{
            int nxt = 0, Left;
            if (A[i] != 0) Left = i;
            else Left = -1;

            //for k in range(i, j + 1):
            for (int k = i; k <= j; k++) {
                if (k == j && A[j] != 0) {
                    nxt += solution(Left, k);
                }
                else if (k == j) {
                    continue;
                }
                else if (A[k] == 0 && A[k + 1] != 0){
                    Left = k + 1;
                }
                else if (A[k] != 0 && A[k + 1] == 0) {
                    nxt += solution(Left, k);
                }
            }
            ret = min(ret, H + nxt);
            break;
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << solution(0, N - 1) << endl;
}