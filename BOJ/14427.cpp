#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
int arr[100001];
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    set<pi> S;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        S.insert({arr[i], i});
    }
    int Q;
    cin >> Q;
    while (Q--){
        int a;
        cin >> a;
        if (a == 1){
            int idx, v;
            cin >> idx >> v;
            idx--;
            S.erase({arr[idx], idx});
            arr[idx] = v;
            S.insert({arr[idx], idx});
        }
        else {
            cout << S.begin()->second + 1 << '\n';
        }
    }
}