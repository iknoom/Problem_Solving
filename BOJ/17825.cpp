#include <iostream>
#include <algorithm>

using namespace std;

const int score[] = {
         0,  2,  4,  6,  8,
         10, 12, 14, 16, 18,
         20, 22, 24, 26, 28,
         30, 32, 34, 36, 38,
         13, 16, 19,
         22, 24,
         28, 27, 26,
         25, 30, 35,
         40, 0
};

const int edges[] = {
         1,  2,  3,  4,  5,
         6,  7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 31,
        21, 22, 28,
        24, 28,
        26, 27, 28,
        29, 30, 31,
        32, -1
};

const int blue_edges[] = {
        1, 20, 23, 25
};

const int END = 32;

int answer, dice[10], vst[33], idx[4];

int move(int i, int inc) {
    if (i < 20 && i % 5 == 0) {
        i = blue_edges[i / 5];
        inc--;
    }
    while (inc && i < END) {
        i = edges[i];
        inc--;
    }
    return i;
}

void dfs(int cnt, int sum_score) {
    // cnt가 10이면 최댓값을 갱신하고 종료한다.
    if (cnt == 10) {
        answer = max(answer, sum_score);
        return;
    }
    // 4개의 말 중에서 하나를 선택한다.
    for (int i = 0; i < 4; i++) {
        // if 그 말이 도착점이면 패스한다.
        if (idx[i] == END) {
            continue;
        }
        // 말의 이동 상태를 갱신한다. 파란 간선을 타는지 확인한다.
        int next_idx = move(idx[i], dice[cnt]);
        // if 말 위치가 겹치면 패스한다.
        if (next_idx != END && vst[next_idx]) {
            continue;
        }
        // 백트래킹 한다.
        int before_idx = idx[i];
        idx[i] = next_idx;
        vst[before_idx] = 0;
        vst[next_idx] = 1;
        dfs(cnt + 1, sum_score + score[next_idx]);
        idx[i] = before_idx;
        vst[before_idx] = 1;
        vst[next_idx] = 0;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> dice[i];
    }
    dfs(0, 0);
    cout << answer << '\n';
}