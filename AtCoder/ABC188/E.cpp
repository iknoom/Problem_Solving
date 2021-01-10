#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 200005;
const int INF = 2e9+5;
bool finished[MAX];
int dfsn[MAX];
int sn[MAX];
vector<int> adj[MAX];
vector<int> stack;
int cnt = 0, SN = 0;
vector<vector<int>> SCC;

int dfs(int curr) {
    cnt++;
    dfsn[curr] = cnt;
    stack.push_back(curr);

    int result = dfsn[curr];
    for (int next : adj[curr]) {
        if (dfsn[next] == 0) result = min(result, dfs(next));
        else if (!finished[next]) result = min(result, dfsn[next]);
    }

    if (result == dfsn[curr]) {
        vector<int> currSCC;
        while (true) {
            int t = stack.back();
            stack.pop_back();
            currSCC.push_back(t);
            finished[t] = true;
            sn[t] = SN;
            if (t == curr) break;
        }

        sort(currSCC.begin(), currSCC.end());
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }

    for (int i = 0; i < N; i++) {
        if (dfsn[i] == 0) {
            dfs(i);
        }
    }

    reverse(SCC.begin(), SCC.end());

    vector<int> B(N, INF); // min value

    int ans = -INF;
    for (int i = 0; i < SN ; i++) {
        vector<int> currSCC = SCC[i];
        int a, b, c;
        a = -INF;
        b = INF;
        c = INF;
        for (int u : currSCC) {
            a = max(a, A[u]);
            b = min(b, A[u]);
            c = min(c, B[u]);
        }

        if (currSCC.size() > 1) {
            ans = max(ans, a - min(b, c));
        } else {
            ans = max(ans, a - c);
        }

        for (int u : currSCC) {
            for (int v : adj[u]) {
                B[v] = min(B[v], min(b, c));
            }
        }
    }
    cout << ans << '\n';
}