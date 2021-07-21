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
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    vector<pi> scd(n);
    for (int i = 0; i < n; i++) {
        cin >> scd[i].y >> scd[i].x;
    }
    sort(all(scd));

    for (auto[d, p] : scd) {
        pq.push(p);
        while (sz(pq) > d) {
            pq.pop();
        }
    }

    int answer = 0;
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }
    cout << answer << '\n';
}