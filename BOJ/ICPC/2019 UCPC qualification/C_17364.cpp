#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>; // e, s
const int MAX_SIZE = 100001;
pi intervals[MAX_SIZE];
int N, K;

int main() {
    cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        cin >> intervals[i].second >> intervals[i].first;
    }
    sort(intervals, intervals + N);

    multiset<int> S;
    int cur_e, ans;
    cur_e = 0;
    ans = 0;
    for (int i = 0; i < N; i++){
        if (intervals[i].second <= cur_e) continue;
        auto lower = S.lower_bound(intervals[i].second);
        if (lower == S.begin()){
            if (S.size() < K - 1) {
                S.insert(intervals[i].first);
                continue;
            }
            ans += 1;
            cur_e = intervals[i].first;
        }
        else {
            S.erase(--lower);
            S.insert(intervals[i].first);
        }
    }
    cout << ans << '\n';
}