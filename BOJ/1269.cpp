#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    set<int> S;
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        S.insert(t);
    }

    int cnt = 0;
    for(int i = 0; i < M; i++) {
        int t;
        cin >> t;
        if(S.find(t) != S.end()){
            cnt++;
        }
    }
    cout << N + M - cnt - cnt << '\n';
}