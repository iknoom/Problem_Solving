#include <bits/stdc++.h>
using namespace std;
int N, population[10], color[10];
bool vst[10];
vector<int> adj[10];

int bfs(int i){
    vst[i] = true;
    queue<int> q;
    q.push(i);
    int ret = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        ret += population[u];
        for (auto v : adj[u]){
            if (!vst[v] && color[u] == color[v]){
                vst[v] = true;
                q.push(v);
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> population[i];
    }
    for (int i = 0; i < N; i++){
        int M;
        cin >> M;
        while (M--) {
            int j;
            cin >> j;
            j--;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    int ans = 1e9;
    for (int choice = 1; choice < (1 << N); choice++){
        fill(color, color + N, 0);
        for (int i = 0; i < N; i++){
            if ((1 << i) & choice){
                color[i] = 1;
            }
        }
        fill(vst, vst + N, false);
        int red, blue, count;
        red = 0; blue = 0; count = 0;
        for (int i = 0; i < N; i++){
            if (!vst[i]){
                count++;
                if (color[i] == 1){
                    red += bfs(i);
                }
                else {
                    blue += bfs(i);
                }
            }
        }
        if (red && blue && count == 2){
            ans = min(ans, abs(red - blue));
        }
    }

    if (ans == 1e9){
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }
}