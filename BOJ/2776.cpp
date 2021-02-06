#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N;
        map<int, int> dic;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            dic[a]++;
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            int b;
            cin >> b;
            if (dic[b] > 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }



    }
}