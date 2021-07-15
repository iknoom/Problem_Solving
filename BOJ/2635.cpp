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
    int N;
    cin >> N;
    int answer = 0;
    vector<int> answer_list;
    for (int i = 1; i <= N; i++) {
        vector<int> v;
        v.push_back(N);
        v.push_back(i);
        while (v[v.size() - 2] - v[v.size() - 1] >= 0) {
            v.push_back(v[v.size() - 2] - v[v.size() - 1]);
        }
        if (answer < sz(v)) {
            answer = sz(v);
            answer_list = v;
        }
    }
    cout << answer << '\n';
    for (auto k : answer_list) {
        cout << k << ' ';
    }
    cout << '\n';
}