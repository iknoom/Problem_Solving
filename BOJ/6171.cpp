#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<long long, long long>;
const int INF = 1e9;

struct line {
    long long a, b, px, py;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pi> HW(N);
    for (int i = 0; i < N; i++) {
        cin >> HW[i].y >> HW[i].x;
    }
    sort(all(HW));
    vector<long long> H, W;
    for (auto[h, w]:HW) {
        while (!W.empty() && W.back() <= w) {
            H.pop_back(); W.pop_back();
        }
        H.push_back(h); W.push_back(w);
    }

    int M = sz(H);
    vector<long long> dp(M + 1);
    vector<line> st;
    st.push_back({W[0], 0, -INF, 1});
    for (int i = 0; i < M; i++) {
        // fill dp[i + 1]
        int l = 0, r = sz(st) - 1;
        if (st.back().px <= H[i] * st.back().py) {
            dp[i + 1] = st.back().a * H[i] + st.back().b;
        } else {
            while (l + 1 < r) {
                int mid = (l + r) / 2;
                if (st[mid].px <= H[i] * st[mid].py) {
                    l = mid;
                } else{
                    r = mid;
                }
            }
            dp[i + 1] = st[l].a * H[i] + st[l].b;
        }
        if (i == M - 1) break;
        // push line
        line cline;
        cline.a = W[i + 1];
        cline.b = dp[i + 1];
        while (true) {
            // get point
            long long cx, cy;
            cx = cline.b - st.back().b;
            cy = st.back().a - cline.a;
            if (st.back().px * cy >= cx * st.back().py) {
                st.pop_back();
            } else {
                cline.px = cx;
                cline.py = cy;
                st.push_back(cline);
                break;
            }
        }
    }
    cout << dp.back() << '\n';
}