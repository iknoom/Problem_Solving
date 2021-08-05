#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    vector<int> idx;
    for (int i = 1; i < N - 1; i++) {
        idx.push_back(i);
    }
    int answer = -1;
    do {
        int cur = 0, i, j;
        vector<bool> vst(N);
        for (auto cur_idx : idx) {
            vst[cur_idx] = true;
            i = j = cur_idx;
            while (vst[i]) i--;
            while (vst[j]) j++;
            cur += v[i] * v[j];
        }
        answer = max(answer, cur);
    } while (next_permutation(idx.begin(), idx.end()));
    cout << answer << '\n';
}
