#include <bits/stdc++.h>
using namespace std;

int N, k, m, L;
string t;

int query() {
    vector<int> v;
    int cur = 0;
    for (int i = N - 1; i > N - k; i--) {
        cur += (t[i] - '0') * L;
        cur /= 10;
    }
    for (int i = N - k; i >= 0; i--) {
        cur += (t[i] - '0') * L;
        v.push_back(cur);
        cur /= 10;
    }
    sort(v.begin(), v.end());

    int ret = 1;
    queue<int> q;
    for (auto val : v) {
        q.push(val);
        while (q.back() - q.front() > m) q.pop();
        ret = max(ret, (int)q.size());
    }
    return ret;
}

void solution() {
    cin >> N >> k >> m;
    cin >> t;
    k = min(k, N);
    L = 1;
    for (int i = 0; i < k - 1; i++) L *= 10;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        char tmp = t[i];
        t[i] = '1';
        ans = max(ans, query());
        t[i] = tmp;
    }
    ans = max(ans, query());
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T, test_case;

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cout << "Case #" << test_case+1 << endl;
        solution();
    }
    return 0;
}