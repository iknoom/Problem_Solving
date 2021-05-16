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
int answer, N, A[13], selected[13];
vector<int> st;

bool check() {
    int cur = st.back(), cnt = 1;
    for (int i = (int)st.size() - 1; i >= 0; i--) {
        if (cur < st[i]) {
            cur = st[i];
            cnt++;
        }
    }
    return A[(int)st.size() - 1] == cnt;
}

void dfs(int all) {
    if (all == N) {
        answer++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (selected[i]) {
            continue;
        }
        selected[i] = 1;
        st.push_back(i);
        if (check()) {
            dfs(all + 1);
        }
        selected[i] = 0;
        st.pop_back();
    }
}

void solution() {
    answer = 0;
    st.clear();
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> A[i];
        selected[i] = 0;
    }
    dfs(0);
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        solution();
        cout << "Case #" << c << ": " << answer << '\n';
    }
}