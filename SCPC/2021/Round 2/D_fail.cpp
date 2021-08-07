#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
int N, K;

void solution() {
    // input
    string Text;
    vector<string> dict(K);
    cin >> Text;
    for (int i = 0; i < K; i++) {
        cin >> dict[i];
    }
    long long answer = 0;
    for (int p = 0; p < K; p++) {
        long long match = 0;
        int M = sz(dict[p]);
        // make fail
        vector<int> fail(M);
        vector<int> bits(M);
        int cur = 0;
        for (int i = 0; i < M; i++) {
            cur |= (1 << (dict[p][i] - 'a'));
            bits[i] = cur;
        }
        for (int i = 1, j = 0; i < M; i++) {
            while(j > 0 && dict[p][i] != dict[p][j]) j = fail[j-1];
            if(dict[p][i] == dict[p][j]) fail[i] = ++j;
        }

        // get match
        vector<int> to_match(26, -1);
        for(int i = 0, j = 0; i < N; i++){
            while(j > 0 && to_match[dict[p][j] - 'a'] >= 0 && (Text[i] - 'a') != to_match[dict[p][j] - 'a']) {
                j = fail[j-1];
                for (int bit = 0; bit < 26; bit++) {
                    if (!(bits[j] & (1 << bit))) {
                        to_match[bit] = -1;
                    }
                }
            }
            if (to_match[dict[p][j] - 'a'] < 0) {
                to_match[dict[p][j] - 'a'] = Text[i] - 'a';
            }

            if (Text[i] - 'a' == to_match[dict[p][j] - 'a']){
                if(j == M - 1){
                    match++;
                    j = fail[j];
                    for (int bit = 0; bit < 26; bit++) {
                        if (!(bits[j] & (1 << bit))) {
                            to_match[bit] = -1;
                        }
                    }
                }
                else j++;
            }
        }
        answer += (p + 1) * match;
    }
    cout << answer << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << '\n';
        cin >> N >> K;
        if (N * K > 10000000) {
            cout << 0 << '\n';
        } else {
            solution();
        }
    }
}