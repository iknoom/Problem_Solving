#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, K;
    cin >> N >> K;
    vector<long double> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    long double answer = 1e18;
    for (long long k = K; k <= N; k++) {
        for (int i = 0; i < N - k + 1; i++) {
            long double sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += v[j];
            }
            long double avr = sum / k;
            long double sum2 = 0;
            for (int j = i; j < i + k; j++) {
                sum2 += pow(v[j] - avr, 2);
            }
            long double var = sum2 / k;
            answer = min(answer, sqrt(var));
        }
    }
    cout << fixed;
    cout.precision(15);
    cout << answer << '\n';
}