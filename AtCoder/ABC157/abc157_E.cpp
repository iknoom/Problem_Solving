#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
int N, Q;
string S;
ll a[26][500001];
ll tree[26][500001];

ll sum(int cur, int i) {
    ll ans = 0;
    while (i > 0) {
        ans += tree[cur][i];
        i -= (i & -i);
    }
    return ans;
}
void update(int cur, int i, int diff) {
    while (i <= N) {
        tree[cur][i] += diff;
        i += (i & -i);
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    cin >> S;
    cin >> Q;

    for (int i = 1; i <= N; i++) {
        char c = S[i - 1];
        update(c - 97, i, 1);
    }

    for (int i = 1; i <= Q; i++) {
        int c;
        cin >> c;
        if (c == 1) {
            int j; char q;
            cin >> j;
            cin >> q;
            //cout << q << "!" << endl;
            char p = S[j - 1];
            //cout << p << "!" << endl;
            S[j - 1] = q;
            if (p == q) continue;
            update(p - 97, j, -1);
            update(q - 97, j, 1);
        }
        else {
            int a, b, ret;
            cin >> a >> b;
            ret = 0;
            for (int j = 0; j < 26; j++) {

                if (sum(j, b) - sum(j, a - 1)) {
                    //cout << j << " " << sum(j, b) << " " << sum(j, a - 1) << endl;
                    ret++;
                }
            }
            cout << ret << endl;
        }
    }

}
