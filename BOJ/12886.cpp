#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
using ti = tuple<int, int, int>;
int vst[1501][1501];

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    vst[A][B] = 1;
    queue<ti> q;
    q.push({A, B, C});
    int answer = 0;
    while (!q.empty()) {
        auto[a, b, c] = q.front();
        q.pop();
        if (a == b && b == c) {
            answer = 1;
        }
        if (a != b) {
            int na, nb;
            if (a > b) {
                na = a - b;
                nb = b + b;
            } else {
                na = a + a;
                nb = b - a;
            }
            if (!vst[na][nb]) {
                vst[na][nb] = 1;
                q.push({na, nb, c});
            }
        }
        if (a != c) {
            int na, nc;
            if (a > c) {
                na = a - c;
                nc = c + c;
            } else {
                na = a + a;
                nc = c - a;
            }
            if (!vst[na][b]) {
                vst[na][b] = 1;
                q.push({na, b, nc});
            }
        }
        if (b != c) {
            int nb, nc;
            if (b > c) {
                nb = b - c;
                nc = c + c;
            } else {
                nb = b + b;
                nc = c - b;
            }
            if (!vst[a][nb]) {
                vst[a][nb] = 1;
                q.push({a, nb, nc});
            }
        }
    }
    cout << answer << '\n';
}