#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
using pi = pair<int, int>;

vector<int> st_a; // max
vector<int> st_b; // min

long long n;

long long ans = 0;

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int L;
        cin >> L;
        vector<int> v(L);
        for (int i = 0; i < L; i++)
            cin >> v[i];
        bool flag = true;

        for (int i = 0; i < L - 1; i++) {
            if (v[i] < v[i + 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            st_a.push_back(v[0]);
            st_b.push_back(v[L - 1]);
        }
    }
    if (!st_b.empty()) {
        sort(st_b.begin(), st_b.end());
        int T = st_b.size();
        for (auto k : st_a) {
            int x;
            x = lower_bound(st_b.begin(), st_b.end(), k) - st_b.begin();
            ans += T - x;
        }
    }
    cout << n*n - ans;

}
