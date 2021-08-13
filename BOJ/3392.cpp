#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using ti = tuple<int, int, int, int>;
const int SIZE = 131072;

long long arr[SIZE], cnt[SIZE];
int start;

void init() {
    start = 1;
    while (start < 30000) start *= 2;
}

void update(int l, int r, int s, int e, int i, long long val){
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        arr[i] += val;
    } else {
        int mid = (s + e) / 2;
        update(l, r, s, mid, i * 2, val);
        update(l, r, mid + 1, e, i * 2 + 1, val);
    }
    if (arr[i] > 0) {
        cnt[i] = e - s + 1;
    } else {
        if (s == e) {
            cnt[i] = 0;
        } else {
            cnt[i] = cnt[i * 2] + cnt[i * 2 + 1];
        }
    }
}

int main() {
    fastio;
    init();
    int N;
    cin >> N;
    vector<ti> sweep;
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sweep.emplace_back(x1, y1, y2, 1);
        sweep.emplace_back(x2, y1, y2, -1);
    }
    sort(all(sweep));
    int before = -1; long long answer = 0;
    for (auto[x, y1, y2, t] : sweep) {
        if (before >= 0) {
            answer += (long long)(x - before) * cnt[1];
        }
        update(y1, y2 - 1, 0, 30000, 1, t);
        before = x;
    }
    cout << answer << '\n';
}