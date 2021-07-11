#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;

int N;
vector<int> children[50];

int dfs(int u) {
    vector<int> ret;
    for (int child : children[u]) {
        ret.push_back(dfs(child));
    }
    if (ret.empty()) {
        return 0;
    } else {
        sort(all(ret), greater<int>());
        for (int i = 0; i < sz(ret); i++) {
            ret[i] += i + 1;
        }
        return *max_element(all(ret));
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int parent;
        cin >> parent;
        children[parent].push_back(i);
    }
    cout << dfs(0) << '\n';
}