#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    vector<int> sausages(N, M), tasters(M, N);
    int answer = 0;
    for (int i = 0; i < M; i++) {
        while (tasters[i]) {
            if (tasters[i] >= sausages.back()) {
                tasters[i] -= sausages.back();
                sausages.pop_back();
            }
            else {
                sausages.back() -= tasters[i];
                tasters[i] = 0;
                answer++;
            }
        }
    }
    cout << answer << '\n';
}