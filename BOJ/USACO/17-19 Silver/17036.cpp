#include <iostream>
#include <algorithm>
using namespace std;
int N, C[100000];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C, C + N);

    int ans1 = 1e9, ans2;

    int i = 0, j = 0;
    while (j < N) {
        while (j < N && C[j] < C[i] + N) j++;
        ans1 = min(ans1, N - (j - i));
        i++;
    }

    int lc = 0, rc = 0;
    for (int i = 1; i < N - 1; i++) {
        lc += C[i + 1] - C[i] - 1;
        rc += C[i] - C[i - 1] - 1;
    }
    ans2 = max(lc, rc);

    if (lc == 0 && rc > 1) ans1++;
    if (rc == 0 && lc > 1) ans1++;
    cout << ans1 << endl;
    cout << ans2 << endl;
}
