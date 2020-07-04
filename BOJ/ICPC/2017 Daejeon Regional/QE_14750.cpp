#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
using pi = pair<int, int>;
int N, K, H, M, B[50][5];
bool vst[300];
pi walls[1002];
vector<int> adj[300];
pi mice[300], holes[50];

int CCW(pi A, pi B, pi C) {
    ll op = (ll)A.first * B.second + (ll)B.first * C.second + (ll)C.first * A.second;
    op -= (ll)A.first * C.second + (ll)B.first * A.second + (ll)C.first * B.second;
    if (op > 0) return 1;
    if (op < 0) return -1;
    else return 0;
}

bool is_intersect(pi a1, pi b1, pi a2, pi b2) {
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    int p = CCW(a1, b1, a2) * CCW(a1, b1, b2);
    int q = CCW(a2, b2, a1) * CCW(a2, b2, b1);
    if (p == 0 && q == 0) {
        if (b1 < a2 || b2 < a1) return false;
        else return true;
    }
    if (p <= 0 && q <= 0) return true;
    else return false;
}

bool is_in_wall(pi a1, pi b1, pi t) {
    if (a1 > b1) swap(a1, b1);
    if (a1.first == b1.first && a1.first == t.first && a1.second <= t.second && t.second <= b1.second)
        return true;
    if (a1.second== b1.second && a1.second == t.second && a1.first <= t.first && t.first <= b1.first)
        return true;
    return false;
}

bool dfs(int a) {
    vst[a] = true;
    for (int b : adj[a]) for (int i = 0; i < K; i++) {
            if (B[b][i] < 0 || !vst[B[b][i]] && dfs(B[b][i])) {
                B[b][i] = a;
                return true;
            }
        }
    return false;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K >> H >> M;
    for (int i = 0; i < N; i++)
        cin >> walls[i].first >> walls[i].second;
    walls[N] = walls[0];

    for (int i = 0; i < H; i++)
        cin >> holes[i].first >> holes[i].second;
    for (int i = 0; i < M; i++)
        cin >> mice[i].first >> mice[i].second;

    for (int i = 0; i < M; i++) for (int j = 0; j < H; j++) {
            bool match = true;
            for (int k = 0; k < N; k++) {
                if (is_in_wall(walls[k], walls[k + 1], holes[j])) continue;
                if (is_intersect(walls[k], walls[k + 1], holes[j], mice[i])) match = false;
            }
            if (match) adj[i].push_back(j);
        }

    for (int i = 0; i < H; i++)
        fill(B[i], B[i] + K, -1);

    bool ans = true;
    for (int i = 0; i < M; i++) {
        fill(vst, vst + M, false);
        if (!dfs(i)) ans = false;
    }

    if (ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}