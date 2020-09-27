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

void multiply(const vector<int> &a, const vector<int> &b, vector<long long> &res) {
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
    int n, l, m;
    long long W;
    cin >> n >> l >> m >> W;

    vector<vector<int>> x(m), y(m);
    vector<vector<long long>> c(m);
    vector<long long> ans(n - l + 1, 0);

    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        int t;
        cin >> t;
        x[i].push_back(t);
    }

    for (int i = 0; i < m; i++) for (int j = 0; j < l; j++) {
        int t;
        cin >> t;
        y[i].push_back(t);
    }

    for (int i = 0; i < m; i++) {
        reverse(y[i].begin(), y[i].end());
        multiply(x[i], y[i], c[i]);
        for (int j = 0; j < n - l + 1; j++) {
            ans[j] += c[i][l + j - 1];
        }
    }
    int result = 0;

    for (int i = 0; i < n - l + 1; i++) {
        if (ans[i] > W) {
            result++;
        }
    }
    cout << result << '\n';
}