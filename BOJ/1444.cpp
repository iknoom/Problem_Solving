#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int SIZE = 676;
int B[SIZE];
set<int> adj[SIZE];
bool vst[SIZE];

bool dfs(int u) {
    vst[u] = true;
    for (auto v : adj[u]) {
        if (B[v] == -1 || !vst[B[v]] && dfs(B[v])) {
            B[v] = u;
            return true;
        }
    }
    return false;
}

int getIdx(string word) {
    int a, b;
    if ('a' <= word[0] && word[0] <= 'z') {
        a = word[0] - 'a';
        b = word[1] - 'A';
    } else {
        a = word[0] - 'A';
        b = word[1] - 'a';
    }
    return a * 26 + b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string sentence;
    cin >> sentence;
    if (sz(sentence) == 2) {
        cout << 1 << '\n';
        return 0;
    }
    if (sz(sentence) == 3) {
        cout << 2 << '\n';
        return 0;
    }
    string prefix, suffix;
    prefix = sentence.substr(0, 2);
    suffix = sentence.substr(sz(sentence) - 2, 2);
    for (int i = 1; i < sz(sentence) - 2; i += 2) {
        string word = sentence.substr(i, 2);
        if (word == prefix || word == suffix) {
            continue;
        }
        int idx = getIdx(word);
        if (i - 1 >= 1) {
            string wordL = sentence.substr(i - 1, 2);
            if (wordL != prefix && wordL != suffix) {
                adj[idx].insert(getIdx(wordL));
            }
        }
        if (i + 1 < sz(sentence) - 2) {
            string wordR = sentence.substr(i + 1, 2);
            if (wordR != prefix && wordR != suffix) {
                adj[idx].insert(getIdx(wordR));
            }
        }
    }
    fill_n(B, SIZE, -1);
    int answer = 0;
    for (int i = 0; i < SIZE; i++) {
        fill_n(vst, SIZE, false);
        if (dfs(i)) {
            answer++;
        }
    }
    cout << answer + 1 + (prefix != suffix) << '\n';
}