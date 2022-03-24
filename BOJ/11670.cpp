#include <bits/stdc++.h>

using namespace std;
using pi = pair<long long, long long>;
int N;
vector<pi> ab;
char A[2500];
map<long long, int> B;
bool vst[2500];

bool dfs(int u) {
    vst[u] = true;
    long long add = ab[u].first + ab[u].second;
    if (B.find(add) == B.end() || !vst[B[add]] && dfs(B[add])) {
        A[u] = '+';
        B[add] = u;
        return true;
    }
    long long sub = ab[u].first - ab[u].second;
    if (B.find(sub) == B.end() || !vst[B[sub]] && dfs(B[sub])) {
        A[u] = '-';
        B[sub] = u;
        return true;
    }
    long long mul = ab[u].first * ab[u].second;
    if (B.find(mul) == B.end() || !vst[B[mul]] && dfs(B[mul])) {
        A[u] = '*';
        B[mul] = u;
        return true;
    }
    return false;
}

long long eval(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long a, b;
        cin >> a >> b;
        ab.emplace_back(a, b);
    }
    for (int i = 0; i < N; i++) {
        fill_n(vst, N, false);
        if (!dfs(i)) {
            cout << "impossible" << '\n';
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ab[i].first << ' ' << A[i] << ' ' << ab[i].second;
        cout << " = " << eval(ab[i].first, ab[i].second, A[i]) << '\n';
    }
}