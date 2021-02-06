#include <bits/stdc++.h>
using namespace std;

int l, m, n;
int sl, sm, sn;
using pi = pair<int, int>;
pi left_wall[1001], right_wall[1001], center[1001]; // y, dx

int sweep(int x0, int idx){
    vector<pi> ycords;
    for (int i = 0; i < l; i++) ycords.emplace_back(left_wall[i].first, i);
    for (int i = 0; i < m; i++) ycords.emplace_back(right_wall[i].first, i + 1000);
    for (int i = 0; i < n; i++) ycords.emplace_back(center[i].first, i + 2000);
    sort(ycords.begin(), ycords.end());

    int ret = 0;

    int left_x, right_x, mid_x, diff, prv_y;
    left_x = sl;
    right_x = sm;
    mid_x = sn;
    diff = 0;
    prv_y = 0;
    cout << x0 << ' ' << idx << "!" << endl;
    for (auto k : ycords) {
        cout << prv_y << "->" << k.first << endl;
        if (left_x <= mid_x && mid_x <= right_x) {
            ret += (k.first - prv_y);
        }
        if (k.second < 1000) left_x += left_wall[k.second].second;
        else if (k.second < 2000) right_x += right_wall[k.second - 1000].second;
        else if (k.second < 3000) {
            int i = k.second - 2000;
            if (i < idx) {
                mid_x += center[i].second;
            }
            else if (i == idx) {
                if (center[i].second >= 0) {
                    if (x0 < mid_x) return 0;
                    diff = x0 - (mid_x + center[i].second);
                    if (diff > 0) return 0;
                    mid_x += center[i].second + diff;
                    mid_x += diff;
                } else {
                    if (x0 > mid_x) return 0;
                    diff = x0 - (mid_x + center[i].second);
                    if (diff < 0) return 0;
                    mid_x += center[i].second + diff;
                    mid_x += diff;
                }
            } else {
                mid_x -= center[i].second;
            }
        }
        prv_y = k.first;
        cout << left_x << ' ' << mid_x << ' ' << right_x << endl;
    }
    cout << ret << '!' << endl;
    return ret;

}

int solution() {
    cin >> l >> m >> n;
    int y = 0, dx, dy;
    cin >> sl;
    for (int i = 0; i < l - 1; i++) {
        cin >> dy >> dx;
        y += dy;
        left_wall[i].first = y;
        left_wall[i].second = dx;
    }
    cin >> dy;
    y += dy;
    left_wall[l - 1].first = y;
    left_wall[l - 1].second = 0;

    y = 0;
    cin >> sm;
    for (int i = 0; i < m - 1; i++) {
        cin >> dy >> dx;
        y += dy;
        right_wall[i].first = y;
        right_wall[i].second = dx;
    }
    cin >> dy;
    y += dy;
    right_wall[m - 1].first = y;
    right_wall[m - 1].second = 0;

    y = 0;
    cin >> sn;
    for (int i = 0; i < n - 1; i++) {
        cin >> dy >> dx;
        y += dy;
        center[i].first = y;
        center[i].second = dx;
    }
    cin >> dy;
    y += dy;
    center[n - 1].first = y;
    center[n - 1].second = 0;

    int ret = 0;
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < n - 1; j++) {
            ret = max(ret, sweep(i - 200, j));
        }
    }
    ret = max(ret, sweep(-1, 1000));
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
        cout << "Case #" << test_case+1 << '\n';
        cout << solution() << '\n';
    }
    return 0;
}