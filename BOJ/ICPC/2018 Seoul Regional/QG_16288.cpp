#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, k;
    queue<int> q;

    cin >> N >> k;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }

    int cnt = 0;

    while (!q.empty()) {
        int cur = -1;
        int L = q.size();
        cnt += 1;
        for (int i = 0; i < L; i++) {
            int pop = q.front();
            if (cur < pop) cur = pop;
            else q.push(pop);
            q.pop();
        }
    }
    cout << (k < cnt? "NO" : "YES");
}