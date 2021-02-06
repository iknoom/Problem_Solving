#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N, M, ans = 0;
    cin >> N >> M;
    set<string> S;
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        S.insert(tmp);
    }
    for(int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        if(S.find(tmp) != S.end()){
            ans++;
        }
    }
    cout << ans << '\n';
}