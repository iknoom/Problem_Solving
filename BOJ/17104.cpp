#include <bits/stdc++.h>

using namespace std;

const double pi = 3.14159265358979323846264;
typedef complex<double> base;

void fft(vector<base> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len = 2; len <= n; len <<= 1){
        double ang = 2 * pi / len * (invert ? -1 : 1);
        base wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len){
            base w(1);
            for (int j = 0; j < len / 2; j++){
                base u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res) {
    vector <base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa,false);
    fft(fb,false);

    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    fft(fa,true);
    res.resize(n);
    for (int i = 0; i < n; i++) {
        res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int max_n = 1000000;
    vector<int> p(max_n + 1, 1), q(max_n / 2 + 1, 0), r;
    p[0] = p[1] = 0;
    for (int i = 2; i <= max_n; i++) {
        if (p[i] && i * i <= max_n) {
            for (int k = 2; k * i <= max_n; k++)
                p[k * i] = 0;
        }
    }
    for (int i = 3; i <= max_n; i++) {
        q[i / 2] = p[i];
    }
    multiply(q, q, r);
    r[4] += 1;

    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n;
        x = r[(n - 2) / 2];
        y = p[(n / 2)];
        cout << (x - y) / 2 + y << '\n';
    }
}