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

long double get_dist(point p1, point p2, point p3) {
    long double dx = p1.second - p2.second;
    long double dy = p1.first - p2.first;
    long double a = dy;
    long double b = -dx;
    long double c = -(dy * p1.second - dx * p1.first);
    return abs(a * p3.second + b * p3.first + c) / sqrt(a * a + b * b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int c = 1; ; c++) {
        cin >> N;
        if (N == 0) break;
        top = 0;
        dots.clear();
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

        // solution
        long double answer = 1e9;
        for (int i = 0; i < top; i++) {
            point point1, point2;
            point1 = dots[convexhull[i]].second;
            if (i == top - 1) {
                point2 = dots[convexhull[0]].second;
            } else {
                point2 = dots[convexhull[i + 1]].second;
            }
            long double max_dist = 0.0;
            for (int j = 0; j < top; j++) {
                if (j == i || j == i + 1) continue;
                max_dist = max(max_dist, get_dist(point1, point2, dots[convexhull[j]].second));
            }
            answer = min(answer, max_dist);
        }
        ll int_answer = answer * 100.0;
        if (answer * 100.0 - (ll)int_answer > 1e-12) {
            int_answer++;
        }

        cout.precision(2);
        cout << fixed;
        cout << "Case " << c << ": " << (long double)int_answer/100.0 << '\n';
    }
}