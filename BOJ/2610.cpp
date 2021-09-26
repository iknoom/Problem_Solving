#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int i = 0; i < N; i++) dist[i][i] = 0;
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<vector<int>> ccList;
    vector<bool> vst(N);
    for (int i = 0; i < N; i++) {
        if (vst[i]) continue;
        vector<int> cc;
        for (int j = 0; j < N; j++) {
            if (dist[i][j] != INF) {
                cc.push_back(j);
                vst[j] = true;
            }
        }
        ccList.push_back(cc);
    }
    vector<int> answer;
    for (auto cc: ccList) {
        int minIdx = -1, minDist = INF;
        for (auto u : cc) {
            int curMaxDist = 0;
            for (auto v : cc) {
                curMaxDist = max(curMaxDist, dist[u][v]);
            }
            if (minDist > curMaxDist) {
                minIdx = u;
                minDist = curMaxDist;
            }
        }
        answer.push_back(minIdx);
    }

    sort(all(answer));
    cout << sz(answer) << '\n';
    for (auto u : answer) {
        cout << u + 1 << '\n';
    }
}