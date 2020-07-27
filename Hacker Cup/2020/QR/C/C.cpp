#include <bits/stdc++.h>

using namespace std;
using pi = pair<long long, long long>;

long long solution() {
    int N; cin >> N;
    vector<pi> logs;
    for(int i = 0; i < N; i++) {
        long long p, h;
        cin >> p >> h;
        logs.emplace_back(p, h);
    }
    sort(logs.begin(), logs.end());

    map<long long, long long> dict;
    for(auto pi : logs) {
        long long p = pi.first, h = pi.second;

        auto right = dict.find(p);
        if(right == dict.end()){
            dict[p + h] = max(dict[p + h], h);
        } else {
            dict[p + h] = max(dict[p + h], dict[p] + h);
        }

        auto left = dict.find(p - h);
        if(left == dict.end()){
            dict[p] = max(dict[p], h);
        } else {
            dict[p] = max(dict[p], dict[p - h] + h);
        }
    }

    long long ans = 0L;
    for(auto pi : dict) {
        ans = max(ans, pi.second);
    }

    return ans;
}

int main() {
    freopen("timber_input.txt", "r", stdin);
    freopen("timber_output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        long long ans;
        ans = solution();
        cout << "Case #" << i << ": " << ans << '\n';
    }

    fclose(stdin);
    fclose(stdout);
}