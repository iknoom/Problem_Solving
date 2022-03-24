#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

struct SquareMatrix {
    int N;
    vector<vector<long long>> matrix;

    SquareMatrix(int n) : N(n) {
        matrix.resize(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
        }
    }

    void init(const vector<vector<long long>>& arr) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = arr[i][j];
            }
        }
    }

    SquareMatrix& operator*=(const SquareMatrix& m) {
        SquareMatrix tmp(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    tmp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
                    tmp.matrix[i][j] %= MOD;
                }
            }
        }
        return (*this = tmp);
    }

    SquareMatrix& operator=(const SquareMatrix& m) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = m.matrix[i][j];
            }
        }
        return *this;
    }

    SquareMatrix pow(int D) const {
        if (D == 1) {
            SquareMatrix ret(N);
            ret = *this;
            return ret;
        }
        SquareMatrix ret = pow(D / 2);
        ret *= ret;
        if (D % 2 == 1) {
            ret *= *this;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, D;
    cin >> N >> M;
    vector<vector<long long>> arr(N, vector<long long>(N));
    while (M--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        arr[u][v] = 1;
        arr[v][u] = 1;
    }
    cin >> D;

    SquareMatrix squareMatrix(N);
    squareMatrix.init(arr);
    SquareMatrix powMatrix = squareMatrix.pow(D);
    cout << powMatrix.matrix[0][0] << '\n';
}