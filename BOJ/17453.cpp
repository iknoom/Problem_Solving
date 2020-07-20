#include <bits/stdc++.h>
using namespace std;
int n, m, L;
int init[4];
int doors[20][4];
bool is_possible[250];
vector<int> answer[250];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    string tmp;
    cin >> tmp;
    for (int i = 0; i < n; i++) {
        if (tmp[i] == '0') continue;
        int shift = i % 25;
        init[i / 25] |= (1 << shift);
    }

    for (int i = 0; i < m; i++) {
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            if (tmp[j] == '0') continue;
            int shift = j % 25;
            doors[i][j / 25] |= (1 << shift);
        }
    }

    for (int c = 0; c < (1 << m); c++) {
        int cur[4];
        for (int i = 0; i < 4; i++)
            cur[i] = init[i];

        vector<int> ret;
        for (int j = 0; j < m; j++){
            if (c & (1 << j)){
                ret.push_back(j + 1);
                for (int i = 0; i < 4; i++)
                    cur[i] ^= doors[j][i];
            }
        }

        int time = 0;
        for (int i = 0; i < n; i++) {
            int shift = i % 25;
            if (cur[i / 25] & (1 << shift)) time++;
            else time--;
        }
        is_possible[time + n] = true;
        answer[time + n] = ret;
    }

    for (int i = 0; i < 2 * n + 1; i++) {
        if (is_possible[i]){
            cout << answer[i].size() << ' ';
            for (auto k : answer[i]) cout << k << ' ';
            cout << '\n';
        }
        else cout << -1 << '\n';
    }
}