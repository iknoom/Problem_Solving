#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;
int n, k;
unordered_map<int, int> t;

int sol(unordered_map<int, int> clothes, int cnt) {

    if (clothes.empty()) return 0;

    int T = 1e9;
    for (auto q = clothes.begin(); q != clothes.end(); q++)
        T = min(T, q->first);

    vector<pair<int, int>> v;
    for (auto q = clothes.begin(); q != clothes.end(); q++)
        v.push_back({ ((q->first) - T) * (q->second), q->first });

    sort(v.begin(), v.end());

    if (cnt == 1) return 30 + v.back().first;

    else {
        int ret = 1e9;
        int s = 0;
        for (auto q : v) {
            s = q.first;
            clothes.erase(q.second);
            ret = min(ret, 30 + s + sol(clothes, cnt - 1));
        }
        return ret;
    }

}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n >> k;
    while (n--) {
        int a, b;
        cin >> a >> b;
        t[a] = max(t[a], b);
    }
    cout << sol(t, k) << '\n';
}