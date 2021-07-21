#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, K, answer, selected[26];
string str_set[50];

void check() {
    int cur = 0;
    for (int i = 0; i < N; i++) {
        bool flag = true;
        for (char c : str_set[i]) {
            if (selected[c - 'a'] == 0) {
                flag = false;
            }
        }
        if (flag) {
            cur++;
        }
    }
    answer = max(answer, cur);
}

void dfs(int i, int cnt) {
    if (cnt >= K) {
        check();
        return;
    }
    if (i >= 26) {
        return;
    }
    for (int j = i; j < 26; j++) {
        if (selected[j]) continue;
        selected[j] = 1;
        dfs(j + 1, cnt + 1);
        selected[j] = 0;
    }
}

int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> str_set[i];
    }
    if (K - 5 < 0) {
        cout << 0 << '\n';
        return 0;
    }
    K -= 5;
    selected['a' - 'a'] = 1;
    selected['n' - 'a'] = 1;
    selected['t' - 'a'] = 1;
    selected['i' - 'a'] = 1;
    selected['c' - 'a'] = 1;

    dfs(0, 0);
    cout << answer << '\n';
}