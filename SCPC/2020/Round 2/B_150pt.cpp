#include <bits/stdc++.h>
using namespace std;

long long N, M;
long long V[300005];
using pi = pair<long long, int>;

long long solution() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> V[i];
    long long ret = 0;


    set<pi> right_sum;
    long long S = 0;
    for (int i = N - 1; i >= 0; i--) {
        S += V[i];
        right_sum.insert({S, i});
    }

    long long L = 0, R, diff;
    for (int i = 0; i < N; i++) {
        R = S - L;
        diff = R - M;
        if (R <= M) ret = max(ret, R);
        auto it = right_sum.upper_bound({diff, -1});
        if (it != right_sum.end()) {
            ret = max(ret, R - it->first);
        }
        right_sum.erase({R, i});
        L += V[i];
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cout << "Case #" << test_case+1 << endl;
        cout << solution() << endl;
    }
    return 0;
}