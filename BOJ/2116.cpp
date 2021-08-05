#include <bits/stdc++.h>
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

const int rev[] = {5, 3, 4, 1, 2, 0};

int get_idx(int num, vector<int> &dice) {
    for (int i = 0; i < 6; i++) {
        if (dice[i] == num) {
            return i;
        }
    }
}

int get_max_side(int top, int bottom) {
    for (int i = 6; i > 0; i--) {
        if (i == top || i == bottom) continue;
        return i;
    }
}

int main() {
    fastio;
    int N;
    cin >> N;
    vector<vector<int>> dices;
    for (int i = 0; i < N; i++) {
        vector<int> dice(6);
        for (int j = 0; j < 6; j++) {
            cin >> dice[j];
        }
        dices.push_back(dice);
    }
    int answer = 0;
    for (int i = 1; i <= 6; i++) {
        int bottom = i, cur = 0;
        for (int j = 0; j < N; j++) {
            int bottom_idx = get_idx(bottom, dices[j]);
            int top_idx = rev[bottom_idx];
            int top = dices[j][top_idx];
            cur += get_max_side(top, bottom);
            bottom = top;
        }
        answer = max(answer, cur);
    }
    cout << answer << '\n';
}