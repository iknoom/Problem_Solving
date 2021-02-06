#include <bits/stdc++.h>

using namespace std;
struct node{
    int i;
    long long val;
};
vector<int> adj[500001];
bool vst[500001];

long long BFS(int start) {
    long long ret = 0L;
    queue<node> q;
    vst[start] = true;
    q.push({start, 0L});
    while (!q.empty()){
        node u = q.front();
        q.pop();
        bool flag = true;
        for (auto v : adj[u.i]){
            if (vst[v]) continue;
            flag = false;
            vst[v] = true;
            q.push({v, u.val + 1L});
        }
        if (flag)
            ret += u.val;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    long long count;
    count = BFS(0);
    if (count & 1) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}