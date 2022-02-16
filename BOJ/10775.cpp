#include <bits/stdc++.h>

using namespace std;
int G, P, p[100000], vst[100000];

int find(int u) {
    if (p[u] < 0) {
        return u;
    }
    p[u] = find(p[u]);
    return p[u];
}

void merge(int u, int v) {
    if (u > v) {
        swap(u, v);
    }
    u = find(u);
    v = find(v);
    p[u] += p[v];
    p[v] = u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> G >> P;
    fill(p, p + G, -1);
    int answer = 0;
    while (P--) {
        int i;
        cin >> i;
        i--;
        if (vst[i ]) {
            i += p[find(i)];
            if (i < 0) {
                break;
            }
        }
        vst[i] = 1;
        answer++;
        if (i + 1 < G && vst[i + 1]) {
            merge(i, i + 1);
        }
        if (i - 1 >= 0 && vst[i - 1]) {
            merge(i - 1, i);
        }
    }
    cout << answer << '\n';
}