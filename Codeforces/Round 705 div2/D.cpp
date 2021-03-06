#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int MAX = 200001;
int n, k, prime_count[MAX], query_a[MAX], next_count[MAX];
vector<int> A[MAX];
vector<int> query[MAX];

vector<int> is_n_count[MAX];

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; j++) {
            while (a % j == 0) {
                A[i].push_back(j);
                prime_count[j]++;
                a /= j;
            }
        }
        if (a > 1) {
            A[i].push_back(a);
            prime_count[a]++;
        }
    }
    for (int i = 0; i < k; i++) {
        int a_i, a;
        cin >> a_i >> a;
        a_i--;
        // a 인덱스 저장 : query_a
        query_a[i] = a_i;
        // x 소인수 분해 결과 저장 : query
        for (int j = 2; j * j <= a; j++) {
            while (a % j == 0) {
                query[i].push_back(j);
                prime_count[j]++;
                a /= j;
            }
        }
        if (a > 1) {
            query[i].push_back(a);
            prime_count[a]++;
        }
    }



    // prime count가 n 이상인 것만 처리하기
    for (int i = 1; i < MAX; i++) {
        if (prime_count[i] >= n) {
            is_n_count[i].resize(n);
        }
    }

    long long answer = 1;
    // n
    for (int i = 0; i < n; i++) {
        for (auto a : A[i]) {
            if (is_n_count[a].empty()) continue;
            is_n_count[a][i]++;
            if (is_n_count[a][i] == 1) {
                next_count[a]++;
                if (next_count[a] == n) {
                    answer *= a;
                    answer %= MOD;
                    next_count[a] = 0;
                    for (int j = 0; j < n; j++) {
                        is_n_count[a][j]--;
                        if (is_n_count[a][j] > 0){
                            next_count[a]++;
                        }
                    }
                }
            }
        }
    }

    // k
    for (int i = 0; i < k; i++) {
        int a_i = query_a[i];
        for (auto a : query[i]) {
            if (is_n_count[a].empty()) continue;
            is_n_count[a][a_i]++;
            if (is_n_count[a][a_i] == 1) {
                next_count[a]++;
                if (next_count[a] == n) {
                    answer *= a;
                    answer %= MOD;
                    next_count[a] = 0;
                    for (int j = 0; j < n; j++) {
                        is_n_count[a][j]--;
                        if (is_n_count[a][j] > 0){
                            next_count[a]++;
                        }
                    }
                }
            }
        }
        cout << answer << '\n';
    }








}