#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1000001;
long long n, A, B, C, S[MAX_SIZE];

struct LinearFunc {
    long long a, b, u, d;
    LinearFunc(): LinearFunc(1, 0){}
    LinearFunc(long long a1, long long b1): a(a1), b(b1), u(-1e18), d(1){}
};

bool cross_after(LinearFunc &f, LinearFunc &g) {
    g.u = f.b - g.b;
    g.d = g.a - f.a;
    if (g.d < 0) {
        g.d = -g.d;
        g.u = -g.u;
    }
    return f.u * g.d < g.u * f.d;
}

long long func(long long x) {
    return (A * x * x) + (B * x) + C;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> A >> B >> C;
    for (int i = 0; i < n; i++) cin >> S[i];
    for (int i = 1; i < n; i++) S[i] += S[i - 1];

    long long cur = func(S[0]);
    vector<LinearFunc> stack;
    stack.emplace_back(-2 * A * S[0], (A * S[0] - B) * S[0] + cur);

    int fpos = 0;
    for (int i = 1; i < n; i++) {
        cur = func(S[i]);
        while (fpos + 1 < stack.size() && stack[fpos + 1].u < S[i] * stack[fpos + 1].d) {
            fpos++;
        }
        cur += max(0LL, stack[fpos].a * S[i] + stack[fpos].b);
        LinearFunc L = LinearFunc(-2 * A * S[i], (A * S[i] - B) * S[i] + cur);
        while (!stack.empty()) {
            if (cross_after(stack.back(), L)) break;
            stack.pop_back();
            if (stack.size() == fpos) fpos--;
        }
        stack.push_back(L);
    }
    cout << cur << endl;
}