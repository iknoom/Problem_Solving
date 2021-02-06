#include <bits/stdc++.h>

using namespace std;

struct point{
    long long x0, y0, x, y;
    point(): x0(0), y0(0), x(0), y(0) { }
    point(int x1, int y1, int x2, int y2): x0(x1), y0(y1), x(x2), y(y2) { }

    bool operator <(const point& P){
        // (x/y) < (P.x/P.y)
        if (x * P.y != P.x * y) return x * P.y < P.x * y;
        else if (y0 != P.y0) return y0 < P.y0;
        else return x0 < P.x0;
    }
};

long long ccw(point& a, point& b, point& c) {
    long long ret = (b.x0 - a.x0) * (c.y0 - a.y0) - (b.y0 - a.y0) * (c.x0 - a.x0);
    return ret;
}

vector<int> get_convex(vector<point>& p){
    int N = p.size();
    sort(p.begin(), p.end());

    for (int i = 1; i < N; i++) {
        p[i].x = p[i].x0 - p[0].x0;
        p[i].y = p[i].y0 - p[0].y0;
    }
    sort(++p.begin(), p.end());

    vector<int> convex;
    convex.push_back(0);
    convex.push_back(1);
    int next = 2;

    while (next < N) {
        while (convex.size() >= 2) {
            int first, second;
            first = convex.back(); convex.pop_back();
            second = convex.back();
            if (ccw(p[second], p[first], p[next]) < 0) {
                convex.push_back(first);
                break;
            }
        }
        convex.push_back(next);
        next++;
    }
    return convex;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<point> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].x0 >> points[i].y0;
    }

    vector<int> convex = get_convex(points);
    cout << convex.size() << endl;
}