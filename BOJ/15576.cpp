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
    vector<long long> x(300000, 0), y(300000, 0), z;
    string A, B;
    int a_n, b_n;
    cin >> A >> B;
    if (A == "0" || B == "0") {
        cout << 0 << '\n';
        return 0;
    }
    a_n = A.size();
    b_n = B.size();
    for (int i = 0; i < a_n; i++) {
        x[a_n - 1 - i] = A[i] - '0';
    }
    for (int i = 0; i < b_n; i++) {
        y[b_n - 1 - i] = B[i] - '0';
    }
    multiply(x, y, z);
    int carry = 0;
    vector<int> answer;
    for (int i = 0; i < z.size(); i++) {
        int cur = z[i] + carry;
        carry = cur / 10;
        answer.push_back(cur % 10);
    }
    while (carry) {
        answer.push_back(carry % 10);
        carry /= 10;
    }
    while (answer.back() == 0) answer.pop_back();
    reverse(answer.begin(), answer.end());
    for (auto k : answer) cout << k;
    cout << endl;
}