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
const int MAX = 200;
int N, A[MAX], B[MAX];
vector<int> adj[MAX];
bool vst[MAX];

bool dfs(int u, int selected) {
    vst[u] = true;
    for (auto v : adj[u]) {
        if (v == selected) continue;
        if (B[v] == -1 || !vst[B[v]] && dfs(B[v], selected)) {
            A[u] = v;
            B[v] = u;
            return true;
        }
    }
    return false;
}

bool perfect_matching(int selected) {
    fill(A, A + N, -1);
    fill(B, B + N, -1);
    for (int i = 1; i < N; i++) {
        if (i == selected) continue;
        fill(vst, vst + N, false);
        if (!dfs(i, selected)) {
            return false;
        }
    }
    return true;
}

int main() {
    fastio;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    // fill is_prime
    vector<bool> is_prime(2001, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < 2001; i++) {
        for (int j = i * 2; j < 2001; j += i) {
            is_prime[j] = false;
        }
    }
    // connect edges
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (i == j) continue;
            if (is_prime[arr[i] + arr[j]]) {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> answer;
    for (int selected = 1; selected < N; selected++) {
        if (!is_prime[arr[0] + arr[selected]]) continue;
        if (perfect_matching(selected)) {
            answer.push_back(arr[selected]);
        }
    }
    if (answer.empty()) {
        cout << -1 << '\n';
    } else {
        sort(all(answer));
        for (auto k : answer) {
            cout << k << ' ';
        }
        cout << '\n';
    }
}