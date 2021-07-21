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
    int N, L, P;
    cin >> N;
    vector<pi> st(N);
    for (int i = 0; i < N; i++) {
        cin >> st[i].x >> st[i].y;
    }
    cin >> L >> P;

    sort(all(st));
    int answer = 0;
    priority_queue<int> pq;
    for (auto[a, b] : st) {
        if (L <= a) continue;
        if (P >= L) break;
        // a < L
        while (!pq.empty() && P < a) {
            answer++;
            P += pq.top();
            pq.pop();
        }
        if (P < a) break;
        pq.push(b);
    }

    while (!pq.empty() && P < L) {
        answer++;
        P += pq.top();
        pq.pop();
    }

    if (P >= L) {
        cout << answer << '\n';
    } else {
        cout << -1 << '\n';
    }
}