#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> arr(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0 && arr[i + 1] == 1) {
            answer++;
        }
    }
    while (M--) {
        int a;
        cin >> a;
        if (a == 0) {
            cout << answer << '\n';
        } else {
            int b;
            cin >> b;
            if (arr[b] == 0) {
                answer++;
                arr[b] = 1;
                if (arr[b - 1] == 1) answer--;
                if (arr[b + 1] == 1) answer--;
            }
        }
    }
}