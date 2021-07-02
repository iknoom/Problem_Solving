#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

bool det(int X) {
    while (X) {
        int r = X % 10;
        if (r != 5 && r != 8) return false;
        X /= 10;
    }
    return true;
}

void solution() {
    int NA, NB, NC;
    cin >> NA;
    vector<int> A(NA), B;
    set<int> S;
    for (int i = 0; i < NA; i++) {
        cin >> A[i];
    }
    cin >> NB;
    for (int i = 0; i < NB; i++) {
        int b;
        cin >> b;
        for (auto a : A) B.push_back(a + b);
    }
    cin >> NC;
    vector<int> C(NC);
    for (int i = 0; i < NC; i++) {
        int c;
        cin >> c;
        for (auto b : B) S.insert(b + c);
    }
    int ret = 0;
    for (auto abc : S) {
        if (det(abc)) ret++;
    }
    cout << ret << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}