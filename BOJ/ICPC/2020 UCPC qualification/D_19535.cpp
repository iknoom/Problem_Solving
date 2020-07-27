#include <bits/stdc++.h>
using namespace std;
vector<int> adj[300001];
bool vst[300001];
long long child[300001][3];
int N;
long long D, G;

void get_D(int u){
    vst[u] = true;
    for (auto v : adj[u]){
        if (vst[v]) continue;
        get_D(v);
        child[u][0] += 1;
        child[u][1] += child[v][0];
        child[u][2] += child[v][1];
    }
    D += child[u][2];
    D += child[u][1] * (child[u][0] - 1);
}

long long get_G(int u){
    long long k = (long long) adj[u].size();
    return k * (k - 1) * (k - 2) / 6;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        G += get_G(i);
    }
    get_D(1);

    if (D > G * 3) cout << "D" << '\n';
    else if (D < G * 3) cout << "G" << '\n';
    else cout << "DUDUDUNGA" << '\n';
}