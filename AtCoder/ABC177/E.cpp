#include <bits/stdc++.h>

using namespace std;
int N, A[1000001];
map<int, int> COUNT;
bool is_prime[1001];
vector<int> B[1000001];

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> primes;
    fill(is_prime, is_prime + 1001, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 0; i <= 1000; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            int k = 2;
            while (i * k <= 1000) {
                is_prime[i * k] = false;
                k++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int k = A[i];
        for (int p : primes) {
            if (k % p == 0){
                B[i].push_back(p);
                COUNT[p]++;
                while (k > 1 && k % p == 0) k /= p;
            }
        }
        if (k != 1){
            B[i].push_back(k);
            COUNT[k]++;
        }
    }


    bool pairwise = true, setwise = true;
    for (auto k : COUNT) {
        if (k.second == N) setwise = false;
        if (k.second != 1) pairwise = false;
    }

    if (pairwise) cout << "pairwise coprime" << '\n';
    else if (setwise) cout << "setwise coprime" << '\n';
    else cout << "not coprime" << '\n';
}