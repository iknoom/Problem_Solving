#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using pi = pair<int, int>;
using ppi = pair<int, pi>;

map<int, int> ids, milk;
vector<ppi> v;
int N, G, ans;

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> G;
    milk[G] = 1e9;
    for (int i = 0; i < N; i++) {
        int day, id, diff;
        cin >> day >> id >> diff;
        v.push_back({ day, {id, diff} });
        ids[id] = G;
    }

    sort(v.begin(), v.end());
    for (auto e : v) {
        int id = e.second.first;
        int diff = e.second.second;

        int Ax = (--milk.end())->first;
        int Ay = (--milk.end())->second;

        int a = ids[id];
        int b = a + diff;
        milk[a]--; milk[b]++;
        if (milk[a] == 0) milk.erase(a);
        ids[id] = b;

        int Bx = (--milk.end())->first;
        int By = (--milk.end())->second;

        if (Bx == b && By > 1) ans++;
        else if (Ax == a && Ay > 1) ans++;
        else if (Ax != a && Bx == b) ans++;
        else if (Ax == a && Bx != b) ans++;

    }
    cout << ans << endl;
}