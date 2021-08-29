#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
const long long MOD = 100003;
typedef complex<double> base;

void fft(vector<base> &a, bool inv){
    int n = a.size(), j = 0;
    vector<base> roots(n/2);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit){
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for(int i=0; i<n/2; i++) {
        roots[i] = base(cos(ang * i), sin(ang * i));
    }
    for(int i=2; i<=n; i<<=1){
        int step = n / i;
        for(int j=0; j<n; j+=i){
            for(int k=0; k<i/2; k++){
                base u = a[j+k];
                base v = a[j+k+i/2] * roots[step * k];
                a[j+k] = u+v;
                a[j+k+i/2] = u-v;
            }
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n; // skip for OR convolution.
}

vector<long long> multiply(vector<long long> &v, vector<long long> &w){
    int n = 2;
    while(n < v.size() + w.size()) n <<= 1;
    vector<base> v1(n), v2(n), r1(n), r2(n);
    for(int i=0; i<v.size(); i++){
        v1[i] = base(v[i] >> 15, v[i] & 32767);
    }
    for(int i=0; i<w.size(); i++){
        v2[i] = base(w[i] >> 15, w[i] & 32767);
    }
    fft(v1,0);
    fft(v2,0);
    for(int i=0; i<n; i++){
        int j = (i ? (n - i) : i);
        base ans1 = (v1[i] + conj(v1[j])) * base(0.5,0);
        base ans2 = (v1[i] - conj(v1[j])) * base(0,-0.5);
        base ans3 = (v2[i] + conj(v2[j])) * base(0.5,0);
        base ans4 = (v2[i] - conj(v2[j])) * base(0,-0.5);
        r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0,1);
        r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0,1);
    }
    fft(r1,1);
    fft(r2,1);
    vector<long long> ret(n);
    for(int i=0; i<n; i++){
        long long av = (long long)round(r1[i].real());
        long long bv = (long long)round(r1[i].imag()) + (long long)round(r2[i].real());
        long long cv = (long long)round(r2[i].imag());
        av %= MOD, bv %= MOD, cv %= MOD;
        ret[i] = (av << 30) + (bv << 15) + cv;
        ret[i] %= MOD;
        ret[i] += MOD;
        ret[i] %= MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<long long>> arr;
    for (int i = 0; i < N; i++) {
        long long b;
        cin >> b;
        vector<long long> ab = {b, 1};
        arr.push_back(ab);
    }
    while (sz(arr) > 1) {
        vector<vector<long long>> nxt_arr;
        for (int i = 0; i < sz(arr); i += 2) {
            if (i == sz(arr) - 1) {
                nxt_arr.push_back(arr[i]);
            } else {
                vector<long long> ret;
                nxt_arr.push_back(multiply(arr[i], arr[i + 1]));
            }
        }
        arr = nxt_arr;
    }

    vector<long long> answer = arr[0];
    int Q;
    cin >> Q;
    while (Q--) {
        int idx;
        cin >> idx;
        cout << answer[N - idx] << '\n';
    }
}
