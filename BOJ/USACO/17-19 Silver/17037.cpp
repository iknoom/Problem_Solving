#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;
using ppi = pair<pi, int>;
vector<ppi> v[1001];
int line[1001], N, K;

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x1, x2; pi y;
        cin >> x1 >> y.first >> x2 >> y.second;
        v[x1].push_back({ y, 1 });
        v[x2].push_back({ y, -1 });
    }

    int ans = 0;
    for (int i = 0; i <= 1000; i++) {
        for (auto p : v[i]) {
            for (int i = p.first.first; i < p.first.second; i++)
                line[i] += p.second;
        }
        for (int i = 0; i <= 1000; i++)
            if (line[i] == K) ans++;
    }
    cout << ans << endl;
}