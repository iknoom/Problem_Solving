#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
using pi = pair<long long, long long>;
const long long INF = 2e18+3;
long long w;
int n;
vector<pi> stones;

pi get_xy(int u) {
    long long ux, uy;
    if (u == n) {
        ux = 0; uy = INF;
    }
    else if (u == n + 1) {
        ux = w; uy = INF;
    }
    else {
        ux = stones[u].first;
        uy = stones[u].second;
    }
    return {ux, uy};
}

long long get_dist(long long ux, long long uy, long long vx, long long vy) {
    if (vy == INF || uy == INF) {
        long long dx = abs(ux - vx);
        return dx * dx;
    } else {
        long long dx = abs(ux - vx);
        long long dy = abs(uy - vy);
        return dx * dx + dy * dy;
    }
}

pi det(double max_leap) {
    vector<int> vst(n + 2, -1);
    queue<int> q;
    q.push(n); vst[n] = 1;
    q.push(n + 1); vst[n + 1] = 2;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        auto[ux, uy] = get_xy(u);
        for (int v = 0; v < n + 2; v++) {
            if (u == v) continue;
            if (vst[v] > 0) continue;
            auto[vx, vy] = get_xy(v);
            long long dist = get_dist(ux, uy, vx, vy);
            if (dist <= max_leap) {
                vst[v] = vst[u];
                q.push(v);
            }
        }
    }
    for (int u = 0; u < n + 1; u++) {
        for (int v = u + 1; v < n + 2; v++) {
            if (vst[v] < 0) continue;
            if (vst[u] < 0) continue;
            if (vst[u] == vst[v]) continue;
            auto[ux, uy] = get_xy(u);
            auto[vx, vy] = get_xy(v);
            long long dist = get_dist(ux, uy, vx, vy);
            if (dist <= max_leap * 4) {
                if (uy == INF && vy == INF) {
                    return {ux + vx, 0};
                } else if (uy == INF) {
                    return {ux + vx, vy * 2};
                } else if (vy == INF) {
                    return {ux + vx, uy * 2};
                }
                return {ux + vx, uy + vy};
            }
        }
    }
    return {-1, -1};
}

int main() {
    freopen("froggy.in", "r", stdin);
    freopen("froggy.out", "w", stdout);
    cin >> w >> n;
    for (int i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        stones.emplace_back(x, y);
    }
    double l = 0, r = 9e18;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2;
        auto[x, y] = det(mid);
        if (x < 0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    auto [ax, ay] = det(r);
    if (ax % 2 == 0 && ay % 2 == 0) {
        printf("%lld %lld", ax/2, ay/2);
    } else if (ax % 2 == 0) {
        printf("%lld %lld.5", ax/2, ay/2);
    } else if (ay % 2 == 0) {
        printf("%lld.5 %lld", ax/2, ay/2);
    } else {
        printf("%lld.5 %lld.5", ax/2, ay/2);
    }
}