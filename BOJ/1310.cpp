#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
int N;
typedef pair<ll, ll> point;
typedef pair<ll, pair<ll, ll>> dot;
vector< dot > dots;
int convexhull[100001]; // stack
int top; // stack push idx

int ccw(point a, point b, point c) {
    point ab;
    ab.first = b.first - a.first;
    ab.second = b.second - a.second;
    point bc;
    bc.first = c.first - b.first;
    bc.second = c.second - b.second;
    ll ret = ab.first*bc.second - ab.second*bc.first;
    ret = -ret;
    if (ret > 0) return 1;
    else if (ret == 0) return 0;
    else return -1;
}

ll getDistance(const dot A, const dot B) {
    ll dx = A.second.first - B.second.first;
    ll dy = A.second.second - B.second.second;
    return dx * dx + dy * dy;
}

ll getCross(const point p1, const point p2) {
    return p1.second * p2.first - p1.first * p2.second;
}

bool settingDots(dot A, dot B) {
    int cw = ccw(dots[0].second, A.second, B.second);
    if (cw > 0) return 1;
    if (cw < 0) return 0;
    else if (A.first < B.first) { return 1;	} // dist A < dist B (기준 점에서 거리)
    return 0;
}

void setSlope(const dot P0) {
    for (int i = 1; i < N; i++) {
        dots[i].first = getDistance(P0, dots[i]);
    }
    sort(dots.begin() + 1, dots.end(), settingDots);
}

void ConvexHull() {
    for (int i = 2; i < N; i++) {
        while (top >= 2 && ccw(dots[convexhull[top-2]].second, dots[convexhull[top - 1]].second, dots[i].second) <= 0) top--;
        convexhull[top++]=i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    dots.resize(N);
    for (int i = 0; i < N; i++) {
        ll Dx, Dy;
        cin >> Dx >> Dy;
        dots[i].second.first = Dy;
        dots[i].second.second = Dx;
    }
    sort(dots.begin(), dots.end());
    setSlope(dots[0]);
    convexhull[top++] = 0;
    convexhull[top++] = 1;
    ConvexHull();

    int l = 0, r = 0;
    for (int i = 0; i < top; i++) {
        if (dots[convexhull[i]].second.second < dots[convexhull[l]].second.second) l = i;
        if (dots[convexhull[i]].second.second > dots[convexhull[r]].second.second) r = i;
    }
    long long max_dist = 0;
    for (int i = 0; i <= top; i++) {
        if (max_dist < getDistance(dots[convexhull[l]], dots[convexhull[r]])) {
            max_dist = getDistance(dots[convexhull[l]], dots[convexhull[r]]);
        }
        point left_vector = {dots[convexhull[l]].second.second - dots[convexhull[(l + 1) % top]].second.second,
                             dots[convexhull[l]].second.first - dots[convexhull[(l + 1) % top]].second.first};
        point right_vector = {dots[convexhull[r]].second.second - dots[convexhull[(r + 1) % top]].second.second,
                              dots[convexhull[r]].second.first - dots[convexhull[(r + 1) % top]].second.first};

        if (getCross(left_vector, right_vector) > 0) {
            l = (l + 1) % top;
        } else {
            r = (r + 1) % top;
        }
    }
    cout << max_dist << '\n';
}