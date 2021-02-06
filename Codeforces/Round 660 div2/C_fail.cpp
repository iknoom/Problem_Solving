#include <bits/stdc++.h>

using namespace std;
long long N, M, p[100001], h[100001], sum_p[100001];
vector<long long> adj[100001];
bool visited[100001];
bool answer;


long long fill_p(long long u){
    long long ret = p[u];
    visited[u] = true;
    for (auto v : adj[u]){
        if (visited[v]) continue;
        ret += fill_p(v);
    }
    sum_p[u] = ret;
    return ret;
}

long long solution(long long u){
    visited[u] = true;
    long long happy = (h[u] + sum_p[u]) / 2L;
    long long bad = happy - h[u];
    if (happy + bad != sum_p[u]) answer = false;
    if (happy < 0L || happy > sum_p[u]) answer = false;
    if (bad < 0L || bad > sum_p[u]) answer = false;
    // cout << u << ' ' <<  happy << ' ' << bad << endl;

    long long child_happy = 0L;
    for (auto v : adj[u]) {
        if (visited[v]) continue;
        child_happy += solution(v);
    }

    long long diff = 0L;
    if (p[u] > bad) diff = p[u] - bad;

    if (child_happy > happy - diff) answer = false;

    return happy;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--){
        cin >> N >> M;
        for (int i = 0; i < N; i++) cin >> p[i];
        for (int i = 0; i < N; i++) cin >> h[i];
        for (int i = 0; i < N - 1; i++){
            long long u, v;
            cin >> u >> v;
            adj[v - 1].push_back(u - 1);
            adj[u - 1].push_back(v - 1);
        }

        fill(visited, visited+N, false);
        fill_p(0);

        answer = true;
        fill(visited, visited+N, false);
        solution(0);

        //for (int i = 0; i < N; i++) cout << sum_p[i] << ' ';
        // cout << endl;
        if (sum_p[0] != M) answer = false;

        if (answer) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}