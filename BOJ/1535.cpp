#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int N;
    cin >> N;
    vector<int> W(N), V(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    vector<pi> knapsack;
    knapsack.emplace_back(0, 0);
    for (int i = 0; i < N; i++) {
        int w = W[i], v = V[i];
        vector<pi> tmp;
        for (auto[w_i, v_i] :knapsack) {
            tmp.emplace_back(w_i + w, v_i + v);
        }
        for (auto[w_i, v_i] : tmp) {
            knapsack.emplace_back(w_i, v_i);
        }
    }
    int answer = -1;
    for (auto[w_i, v_i] : knapsack) {
        if (w_i >= 100) continue;
        answer = max(answer, v_i);
    }
    cout << answer << '\n';
}