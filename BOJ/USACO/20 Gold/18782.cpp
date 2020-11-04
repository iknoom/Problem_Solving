#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
int N, vst[MAX], cnt[MAX];
vector<int> adj[MAX];

int dfs(int u, int L) {
    vst[u] = 1;
    vector<int> tmp;
    for (auto v : adj[u]) {
        if (vst[v]) continue;
        int ret = dfs(v, L);
        if (ret < 0) return -1;
        if (ret == 0) continue;
        tmp.push_back(ret);
    }
    int sub_L = 0;
    for (auto& k : tmp) {
        if (cnt[L - k]) cnt[L - k]--;
        else cnt[k]++;
    }
    for (auto& k : tmp) {
        if (cnt[k]) {
            if (sub_L == 0) {
                sub_L = k;
                cnt[k]--;
            } else {
                return -1;
            }
        }
    }
    sub_L++;
    if (sub_L == L) return 0;
    else return sub_L;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> answer(N - 1, -1);
    for (int i = 1; i * i <= N - 1; i++) {
        int Q = (N - 1) / i;
        if (N - 1 == i * Q) {
            fill(vst, vst + N, 0);
            fill(cnt, cnt + i, 0);
            answer[i - 1] = dfs(0, i);
            if (i != Q) {
                fill(vst, vst + N, 0);
                fill(cnt, cnt + Q, 0);
                answer[Q - 1] = dfs(0, Q);
            }
        }
    }
    answer[0] = 1;
    for (auto k : answer) cout << (k == 1 ? 1 : 0);
    cout << '\n';
}