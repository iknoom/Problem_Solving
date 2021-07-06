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
int N, M, level[20000];
vector<int> adj[20000];

int main() {
    fastio;
    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(level, level + N, -1);
    level[0] = 0;
    queue<int> q;
    q.push(0);
    int answer = -1;
    vector<int> answer_list;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (level[u] > answer) {
            answer = level[u];
            answer_list.clear();
            answer_list.push_back(u);
        } else if (level[u] == answer) {
            answer_list.push_back(u);
        }
        for (auto v : adj[u]) {
            if (level[v] >= 0) {
                continue;
            }
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
    cout << *min_element(all(answer_list)) + 1 << ' ';
    cout << answer << ' ';
    cout << sz(answer_list) << '\n';
}