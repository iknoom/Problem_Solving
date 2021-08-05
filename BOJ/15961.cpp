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

int main() {
    fastio;
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> sushi(2 * N), cnt(d + 1);
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
        sushi[i + N] = sushi[i];
    }

    int answer, all = 0;
    for (int i = 0; i < k; i++) {
        cnt[sushi[i]]++;
        if (cnt[sushi[i]] == 1) all++;
    }
    answer = all + (cnt[c] == 0);

    for (int i = k; i < 2 * N; i++) {
        cnt[sushi[i]]++;
        if (cnt[sushi[i]] == 1) all++;
        cnt[sushi[i - k]]--;
        if (cnt[sushi[i - k]] == 0) all--;
        answer = max(answer, all + (cnt[c] == 0));
    }

    cout << answer << '\n';
}