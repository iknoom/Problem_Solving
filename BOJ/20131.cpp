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
    vector<int> a(N), count(N);
    for (int i = 0; i < N - 2; i++) {
        cin >> a[i];
        count[a[i] - 1]++;
    };
    priority_queue<int> hq;
    for (int i = 0; i < N; i++) {
        if (count[i] == 0) {
            hq.push(i + 1);
        }
    }

    vector<pi> edges;
    for (int i = 0; i < N - 2; i++) {
        int u = hq.top(); hq.pop();
        int v = a[i]; count[a[i] - 1]--;
        if (count[a[i] - 1] == 0) {
            hq.push(a[i]);
        }
        if (u > v) swap(u, v);
        edges.emplace_back(u, v);
    }
    int u = hq.top(); hq.pop();
    int v = hq.top(); hq.pop();
    if (u > v) swap(u, v);
    edges.emplace_back(u, v);

    sort(all(edges));
    for (auto edge : edges) {
        cout << edge.x << ' ' << edge.y << '\n';
    }
}