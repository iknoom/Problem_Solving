#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;
int N, all, boy, girl, rest, answer;
vector<int> houses;
map<int, int> left_values;

void dfs(int depth, vector<int> &arr, bool is_A) {
    if (depth == sz(arr)) {
        if (is_A) {
            if (left_values.find(abs(boy - girl)) == left_values.end()) {
                left_values[abs(boy - girl)] = rest;
            } else {
                left_values[abs(boy - girl)] = min(left_values[abs(boy - girl)], rest);
            }
        } else {
            if (left_values.find(abs(boy - girl)) != left_values.end()) {
                answer = min(answer, left_values[abs(boy - girl)] + rest);
            }
        }
        return;
    }

    boy += arr[depth];
    dfs(depth + 1, arr, is_A);
    boy -= arr[depth];

    girl += arr[depth];
    dfs(depth + 1, arr, is_A);
    girl -= arr[depth];

    rest += arr[depth];
    dfs(depth + 1, arr, is_A);
    rest -= arr[depth];
}

void solution() {
    answer = all;
    // divide A B
    vector<int> A = houses;
    vector<int> B;
    for (int i = 0; i < N / 2; i++) {
        B.push_back(A.back());
        A.pop_back();
    }
    // backtrack A, B
    dfs(0, A, true);
    dfs(0, B, false);
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        all = 0;
        houses.clear();
        left_values.clear();
        houses.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> houses[i];
            all += houses[i];
        }
        solution();
    }
}