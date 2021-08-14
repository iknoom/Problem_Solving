#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<long long, long long>;
const int INF = 1e9;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

long long get_max_val(int cnt, priority_queue<long long> &pq, priority_queue<long long> &pq_del) {
    long long ret = 0;
    vector<long long> tmp;
    for (int i = 0; i < cnt; i++) {
        while (!pq.empty() && !pq_del.empty() && pq.top() == pq_del.top()) {
            pq.pop(); pq_del.pop();
        }
        ret += pq.top();
        tmp.push_back(pq.top());
        pq.pop();
    }
    while (!tmp.empty()) {
        pq.push(tmp.back());
        tmp.pop_back();
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, all = 0;
    cin >> N;
    map<long long, vector<pi>> x_set, y_set;
    map<long long, long long> x_sum, y_sum;
    for (int i = 0; i < N; i++) {
        long long x_i, y_i, v_i;
        cin >> x_i >> y_i >> v_i;
        x_set[y_i].emplace_back(x_i, v_i);
        y_set[x_i].emplace_back(y_i, v_i);
        x_sum[y_i] += v_i;
        y_sum[x_i] += v_i;
        all += v_i;
    }
    long long answer = 0;
    priority_queue<long long> x_pq, x_pq_del, y_pq, y_pq_del;
    for (auto[x_sum_i, s] : x_sum) {
        y_pq.push(s);
    }
    for (auto[y_sum_i, s] : y_sum) {
        x_pq.push(s);
    }
    // three y_i
    if (sz(y_pq) > 2) {
        answer = max(answer, get_max_val(3, y_pq, y_pq_del));
    } else {
        cout << all << '\n';
        return 0;
    }
    // three x_i
    if (sz(x_pq) > 2) {
        answer = max(answer, get_max_val(3, x_pq, x_pq_del));
    } else {
        cout << all << '\n';
        return 0;
    }

    // two y_i -> y_pq
    // one x_i update
    for (auto&[x_i, y_i_set] : y_set) {
        // delete
        long long S = 0;
        for (auto[y_i, v_i] : y_i_set) {
            y_pq_del.push(x_sum[y_i]);
            x_sum[y_i] -= v_i;
            y_pq.push(x_sum[y_i]);
            S += v_i;
        }
        // get_max
        answer = max(answer, S + get_max_val(2, y_pq, y_pq_del));
        // add
        for (auto[y_i, v_i] : y_i_set) {
            y_pq_del.push(x_sum[y_i]);
            x_sum[y_i] += v_i;
            y_pq.push(x_sum[y_i]);
        }
    }

    // two x_i -> x_pq
    // one y_i update
    for (auto&[y_i, x_i_set] : x_set) {
        // delete
        long long S = 0;
        for (auto[x_i, v_i] : x_i_set) {
            x_pq_del.push(y_sum[x_i]);
            y_sum[x_i] -= v_i;
            S += v_i;
            x_pq.push(y_sum[x_i]);
        }
        // get_max
        answer = max(answer, S + get_max_val(2, x_pq, x_pq_del));
        // add
        for (auto[x_i, v_i] : x_i_set) {
            x_pq_del.push(y_sum[x_i]);
            y_sum[x_i] += v_i;
            x_pq.push(y_sum[x_i]);
        }
    }
    cout << answer << '\n';

}