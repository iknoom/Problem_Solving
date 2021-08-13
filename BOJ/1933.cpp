#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int N;
    cin >> N;
    vector<ti> sweep;
    for (int i = 0; i < N; i++) {
        int l, h, r;
        cin >> l >> h >> r;
        sweep.emplace_back(l, h, -1);
        sweep.emplace_back(r, h, 1);
    }
    sort(all(sweep));

    priority_queue<int> pq, pq_del;
    vector<pi> answer;
    for (auto[x, h, t] : sweep) {
        if (t == -1) {
            pq.push(h);
        } else {
            pq_del.push(h);
            while (!pq.empty() && !pq_del.empty() && pq.top() == pq_del.top()) {
                pq.pop();
                pq_del.pop();
            }
        }
        int cur_h = 0;
        if (!pq.empty()) {
            cur_h = pq.top();
        }
        if (!answer.empty() && answer.back().first == x) {
            answer.pop_back();
        }
        if (answer.empty() || answer.back().second != cur_h) {
            answer.emplace_back(x, cur_h);
        }
    }
    for (auto[x, h] : answer) {
        cout << x << ' ' << h << ' ';
    }
}