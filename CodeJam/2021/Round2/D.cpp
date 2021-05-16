#include <bits/stdc++.h>

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

bool dfs(int u) {
    vst[u] = true;
    for (auto v : adj[u]) {
        if (B[v] == -1 || !vst[B[v]] && dfs(B[v])) {
            A[u] = v;
            B[v] = u;
            return true;
        }
    }
    return false;
}

void init() {
    for (int i = 0; i < N; i++) {
        adj[i].clear();
    }
}

int solution() {
    int R, C, F, S;
    cin >> R >> C >> F >> S;
    N = R * C;
    init();
    int ret = 0;
    vector<string> before;
    for (int i = 0; i < R; i++) {
        string tmp;
        cin >> tmp;
        before.push_back(tmp);
    }
    vector<string> after;
    for (int i = 0; i < R; i++) {
        string tmp;
        cin >> tmp;
        after.push_back(tmp);
    }
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        if (before[i][j] != after[i][j]) {
            ret++;
        }
    }
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        if ((i + j) % 2) {
            continue;
        }
        if (before[i][j] != after[i][j]) {
            for (int k = 0; k < 4; k++) {
                int x = j + dx[k], y = i + dy[k];
                if (0 > x || C <= x) continue;
                if (0 > y || R <= y) continue;
                if (before[y][x] != after[y][x]) {
                    if (before[y][x] != before[i][j]) {
                        adj[i * C + j].push_back(y * C + x);
                    }
                }
            }
        }
    }
    fill(A, A + N, -1);
    fill(B, B + N, -1);
    for (int u = 0; u < N; u++) {
        fill(vst, vst + N, false);
        if (dfs(u)) {
            ret--;
        }
    }
    return ret;
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cout << "Case #" << c << ": " << solution() << '\n';
    }
}