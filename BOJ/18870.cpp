#include <bits/stdc++.h>

using namespace std;

int n, a[1000001];
vector<int> idx;
map<int, int> getidx;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx.push_back(a[i]);
    }

    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());

    for (int i = 0; i < n; i++) {
        cout << getidx[i] << ' ';
    }

}