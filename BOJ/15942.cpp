#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, k, p;
    cin >> N;
    cin >> k >> p;
    vector<int> answer(N + 1, 0);
    int hi = k, lo = k;
    answer[p] = k;
    // go bottom
    for (int i = p; i <= N; i++) {
        if (answer[i / 2] > 0) {
            answer[i] = ++hi;
        }
    }
    // go top
    for (int i = p / 2; i > 0; i--) {
        if (i * 2 <= N && answer[i * 2] > 0) {
            answer[i] = --lo;
        }
        else if (i * 2 + 1 <= N && answer[i * 2 + 1] > 0) {
            answer[i] = --lo;
        }
    }

    if (hi > N || lo < 1) {
        cout << -1 << '\n';
        return 0;
    }

    int cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (answer[i] > 0) continue;
        if (cnt == lo) cnt = hi + 1;
        answer[i] = cnt++;
    }
    for (int i = 1; i <= N; i++) {
        cout << answer[i] << '\n';
    }
}