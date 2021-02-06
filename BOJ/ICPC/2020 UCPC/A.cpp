#include <bits/stdc++.h>

using namespace std;
int N, S, D;
vector<int> adj[100005];
bool vst[100005];
bool is_to_vst[100005];

int coloring(int u){
    int ret = 0;
    vst[u] = true;
    for(auto v : adj[u]){
        if (vst[v]) continue;
        ret = max(ret, coloring(v));
    }
    if (ret >= D){
        is_to_vst[u] = true;
    }
    return ret + 1;
}

long long solution(int u){
    long long ret = 0LL;
    vst[u] = true;

    if(!is_to_vst[u]) return 0LL;
    for(auto v : adj[u]){
        if(vst[v]) continue;
        ret += solution(v);
    }
    return ret + 2LL;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N >> S >> D;
    for(int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    coloring(S - 1);
    fill(vst, vst + N, false);
    cout << max(0LL, solution(S - 1) - 2LL) << '\n';
}