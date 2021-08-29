#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    string A, B;
    cin >> A >> B;
    vector<int> x(sz(A)), y(sz(B)), z;
    for (int i = 0; i < sz(A); i++) {
        x[i] = A[i] - '0';
    }
    for (int i = 0; i < sz(B); i++) {
        y[i] = B[i] - '0';
    }
    reverse(all(x));
    reverse(all(y));
    multiply(x, y, z);

    for (int i = 0; i < sz(z) - 1; i++) {
        z[i + 1] += z[i] / 10;
        z[i] %= 10;
    }
    while (sz(z) > 1 && z.back() == 0) {
        z.pop_back();
    }
    reverse(all(z));
    for (auto k : z) {
        cout << k;
    }
    cout << '\n';
}
