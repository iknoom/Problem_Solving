#include <bits/stdc++.h>

using namespace std;
vector<int> s;
set<int> adj[100001];


void dfs(int u){
    while (!s.empty() && adj[u].find(s.back()) != adj[u].end()) {
        int v = s.back();
        s.pop_back();
        dfs(v);
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        s.push_back(a);
    }
    reverse(s.begin(), s.end());
    if (s.back() != 0) {
        cout << 0 << '\n';
    }
    else {
        s.pop_back();
        dfs(0);
        if (s.empty()) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}