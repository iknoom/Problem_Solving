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
    int N, K;
    cin >> N >> K;
    K--;
    vector<int> x(1001), y(1001);
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        y[k] = x[k] = 1;
    }

    while (K) {
        if (K % 2 == 1) {
            multiply(x, y, x);
        }
        multiply(y, y, y);
        while (x.back() == 0) x.pop_back();
        while (y.back() == 0) y.pop_back();
        for (int i = 0; i < sz(x); i++) {
            if (x[i]) x[i] = 1;
        }
        for (int i = 0; i < sz(y); i++) {
            if (y[i]) y[i] = 1;
        }
        K /= 2;
    }

    for (int i = 0; i < sz(x); i++) {
        if (x[i]) cout << i << ' ';
    }
    cout << '\n';
}
