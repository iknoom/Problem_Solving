#include <bits/stdc++.h>
using namespace std;

using Double = double;
using base = complex<Double>;
const long double PI = acos(-1.L);

inline unsigned reverseBits(const unsigned n, const unsigned k) {
    unsigned r, i;
    for (r = 0, i = 0; i < k; i++)
        r |= ((n >> i) & 1) << (k - i - 1);
    return r;
}

void FFT(vector<base> &a, bool isReversed = false) {
    const unsigned n = a.size(), k = __builtin_ctz(n);
    unsigned s, i, j;
    for (i = 0; i < n; i++) {
        j = reverseBits(i, k);
        if (i < j)
            swap(a[i], a[j]);
    }
    for (s = 2; s <= n; s *= 2) {
        vector<base> w(s / 2);
        for (i = 0; i < s / 2; i++) {
            Double t = 2 * PI * i / s * (isReversed ? -1 : 1);
            w[i] = base(cos(t), sin(t));
        }
        for (i = 0; i < n; i += s) {
            for (j = 0; j < s / 2; j++) {
                base tmp = a[i + j + s / 2] * w[j];
                a[i + j + s / 2] = a[i + j] - tmp;
                a[i + j] += tmp;
            }
        }
    }
    if (isReversed) {
        for (i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

vector<int> getConvolution(vector<base> &a, vector<base> &b) {
    auto aCopy = a;
    auto bCopy = b;
    int n = 1;
    while (n <= a.size() || n <= b.size()) n *= 2;

    aCopy.resize(n, 0);
    bCopy.resize(n, 0);
    FFT(aCopy);
    FFT(bCopy);

    vector<base> c(n);
    for (unsigned i = 0; i < n; i++)
        c[i] = aCopy[i] * bCopy[i];
    FFT(c, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = (c[i].real() + (c[i].real() > 0 ? 0.5 : -0.5));
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<base> x(2 * n);
    vector<base> y(2 * n);

    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;
        x[i] = x[i + n] = base(xi, 0);
    }

    for (int i = 0; i < n; i++) {
        int yi;
        cin >> yi;
        y[n - 1 - i] = base(yi, 0);
    }

    for (int i = 0; i < n; i++) {
        y[i + n] = base(0, 0);
    }

    vector<int> c = getConvolution(x, y);
    int result = 0;

    for (int i = n - 1; i < 2 * n - 1; i++)
        result = max(result, c[i]);

    cout << result << '\n';
}