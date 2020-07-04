#include <iostream>
#include <algorithm>
using namespace std;
int N, M, C;
int t[100000];

bool check(int L) {
    int s = t[0], bus = 1, cnt = 1;
    for (int i = 1; i < N; i++) {
        cnt++;
        if (cnt > C) {
            s = t[i]; bus++; cnt = 1;
        }
        if (s + L < t[i]) {
            s = t[i]; bus++; cnt = 1;
        }
    }
    if (bus <= M) return true;
    else return false;
}

int main()
{
    cin >> N >> M >> C;
    for (int i = 0; i < N; i++) cin >> t[i];
    sort(t, t + N);

    int L = 0, R = 1e9;
    while (L + 1 < R) {
        int mid = (L + R) / 2;
        if (check(mid)) R = mid;
        else L = mid;
    }
    cout << R << endl;
}
