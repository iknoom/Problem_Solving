#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

void solution() {
    int N, K;
    cin >> N >> K;
    string Text;
    vector<string> dict(K);
    cin >> Text;
    for (int i = 0; i < K; i++) {
        cin >> dict[i];
    }
    long long answer = 0;
    for (int pattern = 1; pattern <= K; pattern++) {
        long long match = 0;
        int M = sz(dict[pattern - 1]);
        vector<vector<int>> idx(26, vector<int>());
        for (int i = 0; i < M; i++) {
            idx[dict[pattern - 1][i] - 'a'].push_back(i);
        }
        for (int s = 0; s < N - M + 1; s++) {
            bool flag = true;
            vector<bool> vst(26, false);
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < sz(idx[i]) - 1; j++) {
                    if (Text[s + idx[i][j]] != Text[s + idx[i][j + 1]]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
                if (!idx[i].empty()) {
                    if (vst[Text[s + idx[i].back()] - 'a']) {
                        flag = false;
                        break;
                    }
                    vst[Text[s + idx[i].back()] - 'a'] = true;
                }
            }
            if (flag) match++;
        }
        answer += pattern * match;
    }
    cout << answer << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << '\n';
        solution();
    }
}