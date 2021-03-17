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

string get_prime(int n) {
    string ret = "_";
    int cur = n;
    for (int k = 2; k * k <= n; k++) {
        int cnt = 0;
        while (cur % k == 0) {
            cur /= k;
            cnt++;
        }
        if (cnt % 2) {
            ret += "_" + to_string(k);
        }
    }
    if (cur != 1) {
        ret += "_" + to_string(cur);
    }
    return ret;
}

void solution() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    int answer = 0;
    int stack = 0;
    set<string> vst;
    for (int i = 0; i < n; i++) {
        if (stack == 0) {
            answer++;
            vst.insert(get_prime(A[i]));
            stack++;
        } else {
            string cur = get_prime(A[i]);
            if (vst.find(cur) == vst.end()) {
                vst.insert(cur);
                stack++;
            } else {
                stack = 1;
                vst.clear();
                vst.insert(cur);
                answer++;
            }
        }
    }
    cout << answer << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}