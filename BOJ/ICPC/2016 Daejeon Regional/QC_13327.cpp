#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;
struct pi { ll x, y; }; 
using seg = tuple<ll, ll, ll, ll>;
const long long INF = 2e18;
ll n, m, u, v, w, l;
pi L[10000], H[10000];
seg lower[10000], upper[10000], Logs[10000];

ll get_dist(seg a, seg b) {
	ll x1, x2, x3, x4, y1, y2, y3, y4, w, h;
	tie(x1, y1, x2, y2) = a;
	tie(x3, y3, x4, y4) = b;
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	if (x3 > x4) swap(x3, x4);
	if (y3 > y4) swap(y3, y4);

	if (x1 == x2 && x3 == x4) {
		w = abs(x3 - x1);
		if (y2 < y3 || y4 < y1) h = min(abs(y3 - y2), abs(y4 - y1));
		else h = 0;
	}
	else if (y1 == y2 && y3 == y4) {
		h = abs(y3 - y1);
		if (x2 < x3 || x4 < x1) w = min(abs(x3 - x2), abs(x4 - x1));
		else w = 0;
	}
	else if (x1 == x2) {
		w = min(abs(x1 - x3), abs(x1 - x4));
		h = min(abs(y3 - y1), abs(y3 - y2));
		if (x3 <= x1 && x1 <= x4) w = 0;
		if (y1 <= y3 && y3 <= y2) h = 0;
	}
	else {
		w = min(abs(x3 - x1), abs(x3 - x2));
		h = min(abs(y1 - y3), abs(y1 - y4));
		if (y3 <= y1 && y1 <= y4) h = 0;
		else if (x1 <= x3 && x3 <= x2) w = 0;
	}
	return w * w + h * h;
}

ll dijkstra() {
	vector<ll> dist(w, INF);
	vector<bool> vst(w, false);
	for (int i = 0; i < u - 1; i++) for (int j = 0; j < w; j++) {
		ll L = get_dist(lower[i], Logs[j]);
		if (L <= l) dist[j] = min(dist[j], L);
	}
	while (true) {
		ll min_dist = INF, idx;
		for (int i = 0; i < w; i++) {
			if (dist[i] < min_dist && !vst[i]) {
				min_dist = dist[i];
				idx = i;
			}
		}
		if (min_dist == INF) break;
		vst[idx] = true;
		for (int i = 0; i < w; i++) {
			if (!vst[i]) {
				ll L = get_dist(Logs[i], Logs[idx]);
				if (L <= l) dist[i] = min(dist[i], dist[idx] + L);
			}
		}
	}

	ll ret = INF;
	for (int i = 0; i < w; i++) for (int j = 0; j < v - 1; j++) {
		ll L = get_dist(Logs[i], upper[j]);
		if (L <= l) ret = min(ret, dist[i] + L);
	}
	return ret;
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> u >> v >> w >> l;
	for (int i = 0; i < u; i++)
		cin >> L[i].x >> L[i].y;
	for (int i = 0; i < v; i++)
		cin >> H[i].x >> H[i].y;

	for (int i = 0; i < u - 1; i++)
		lower[i] = { L[i].x, L[i].y, L[i + 1].x, L[i + 1].y };

	for (int i = 0; i < v - 1; i++)
		upper[i] = { H[i].x, H[i].y, H[i + 1].x, H[i + 1].y };

	for (int i = 0; i < w; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Logs[i] = { x1, y1, x2, y2 };
	}

	ll ans = INF;
	for (int i = 0; i < u - 1; i++) for (int j = 0; j < v - 1; j++) {
		ll L = get_dist(lower[i], upper[j]);
		if (L <= l) ans = min(ans, L);
	}
	ans = min(ans, dijkstra());
	if (ans == INF) ans = -1;
	cout << ans << endl;
}