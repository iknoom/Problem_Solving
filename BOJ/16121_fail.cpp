#include <iostream>
#include <vector>
#define SIZE 300000
#define MOD 998244353
using namespace std;
typedef __int64 ll;

int N, M, K;
ll ans;
bool A[SIZE], B[SIZE], vst[SIZE];
ll A_n_DP[SIZE], A_LN_DP[SIZE], A_QB_DP[SIZE];
ll B_n_DP[SIZE], B_LN_DP[SIZE], B_QB_DP[SIZE];
vector<int> adj[SIZE];


void sol(int u) {
	ll A_n = 0, A_LN = 0, A_QB = 0;
	ll B_n = 0, B_LN = 0, B_QB = 0;
	vst[u] = true;
	ll diff = 0;
	for (auto v : adj[u]) {
		if (!vst[v]) {
			sol(v);
			A_n += A_n_DP[v];
			A_LN += A_LN_DP[v];
			A_QB += A_QB_DP[v];
			B_n += B_n_DP[v];
			B_LN += B_LN_DP[v];
			B_QB += B_QB_DP[v];
			diff += A_n_DP[v] * B_QB_DP[v] + B_n_DP[v] * A_QB_DP[v] + 2 * A_LN_DP[v] * B_LN_DP[v];
		}
	}
	
	ans += A_n * B_QB + B_n * A_QB + 2 * A_LN * B_LN;
	ans -= diff;
	ans %= MOD;

	if (A[u]) {
		ans += B_QB;
		A_n++;
	}

	if (B[u]) {
		ans += A_QB;
		B_n++;
	}
	ans %= MOD;

	A_n_DP[u] = A_n;
	A_LN_DP[u] = A_LN + A_n;
	A_QB_DP[u] = A_QB + A_n + 2 * A_LN;
	B_n_DP[u] = B_n;
	B_LN_DP[u] = B_LN + B_n;
	B_QB_DP[u] = B_QB + B_n + 2 * B_LN;
}

int main(){
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	
	fill(A, A + SIZE, false);
	fill(B, B + SIZE, false);
	fill(vst, vst + SIZE, false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		A[a - 1] = true;
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		B[a - 1] = true;
	}

	ans = 0;
	sol(0);
	cout << ans << endl;
}

