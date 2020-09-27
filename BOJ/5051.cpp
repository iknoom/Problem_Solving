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

void multiply(const vector<long long> &a, const vector<long long> &b, vector<long long> &res) {
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
        res[i] = (long long)(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    vector<long long> x(n, 0), y(n, 0), z;

    for (long long a = 1; a < n; a++) {
        x[(a * a) % n]++;
        y[(a * a * 2) % n]++;
    }
    multiply(x, x, z);
    for (long long i = n; i < z.size(); i++) {
        z[i % n] += z[i];
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long p, q;
        p = z[i] * x[i];
        q = y[i] * x[i];
        result += (p - q)/2 + q;
    }
    cout << result << '\n';
}