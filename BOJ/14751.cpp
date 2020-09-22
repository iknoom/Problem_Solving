#include <bits/stdc++.h>

using namespace std;
const long long MAX_SIZE_d = 1000000000;
const double MAX_SIZE_f = 1000000000;
struct LinearFunc {
    long long dx, dy, b, i, s;
    LinearFunc(): LinearFunc(1, 0){}
    LinearFunc(long long dx1, long long dy1): dx(dx1), dy(dy1), s(0), b(0), i(-1){}

    bool operator <(const LinearFunc& L){
        if (dy * L.dx != L.dy * dx) return dy * L.dx > L.dy * dx;
        else return b > L.b;
    }
};

long long cross(LinearFunc &f, LinearFunc &g) {
    long long a, b;
    a = f.dx * (g.b - f.b);
    b = f.dy - g.dy;
    if (b == 0) return -1e18;
    else return a * MAX_SIZE_d / b;
}

long long minY, maxY;
int n, q;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> maxY >> minY;
    cin >> n;
    vector<LinearFunc> lines(n);
    for (int i = 0; i < n; i++) {
        long long upperX, lowX;
        cin >> upperX >> lowX;
        lines[i].i = i + 1;
        lines[i].b = lowX;
        lines[i].dy = upperX - lowX;
        lines[i].dx = maxY - minY;
    }
    sort(lines.begin(), lines.end());
    vector<LinearFunc> stack;
    stack.push_back(lines[0]);
    for (int i = 1; i < n; i++) {
        while (!stack.empty()) {
            lines[i].s = max(cross(stack.back(), lines[i]), 0LL);
            if (stack.back().s < lines[i].s) break;
            stack.pop_back();
        }
        stack.push_back(lines[i]);
    }

    cin >> q;
    while (q--) {
        long long x; int L, R;
        double tmp;
        cin >> tmp;
        x = (long long)(tmp * MAX_SIZE_f) - (minY * MAX_SIZE_d);
        if (stack.back().s <= x) {
            cout << stack.back().i << '\n';
            continue;
        }
        L = 0; R = stack.size() - 1;
        while (L + 1 < R) {
            int mid = (L + R) / 2;
            if (stack[mid].s <= x) L = mid;
            else R = mid;
        }
        cout << stack[L].i << '\n';
    }
}