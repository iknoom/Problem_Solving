#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<long long, long long>;

void solution() {
    int N;
    cin >> N;
    vector<long long> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    vector<pi> st;
    vector<int> answer(N);
    long long S = 0;
    st.emplace_back(0, 0);
    for (long long i = 1; i <= N; i++) {
        S += P[i - 1];
        while (true) {
            int M = sz(st);
            if (M <= 1) break;
            auto[ax, ay] = st[M - 2];
            auto[bx, by] = st[M - 1];
            // ay/ax > by/bx
            if ((S - ay) * (i - bx) > (i - ax) * (S - by)) {
                st.pop_back();
            } else {
                break;
            }
        }
        answer[i - 1] = i - st.back().x;
        st.emplace_back(i, S);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int i;
        cin >> i;
        cout << answer[i - 2] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}