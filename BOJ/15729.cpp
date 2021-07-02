#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] != A[i]) {
            answer++;
            for (int j = 0; j < 3; j++) {
                if (i + j < N) B[i + j] ^= 1;
            }
        }
    }

    cout << answer << '\n';
}