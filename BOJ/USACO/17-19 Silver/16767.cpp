#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pi = pair<int, int>;
const int MAX = 100000;

priority_queue<pi> pq;
int a[MAX], t[MAX], N;
vector<pi> v;


int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> t[i];
        v.push_back({ a[i], i });
    }
    sort(v.begin(), v.end());

    v.push_back({ 1e9 + 1, MAX + 1 });

    int e_t = 0, ans = 0;

    for (auto p : v) {
        int a_t, snt;

        a_t = p.first; snt = p.second;

        while (!pq.empty() && e_t <= a_t) {
            auto pp = pq.top();
            pq.pop();
            ans = max(ans, e_t - a[-pp.first]);
            e_t += pp.second;
        }

        if (a_t < e_t)
            pq.push({ -snt, t[snt] });

        else if (pq.empty())
            e_t = a_t + t[snt];
    }
    cout << ans << endl;
}
