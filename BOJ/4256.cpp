#include <bits/stdc++.h>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, preorder[1000], inorder[1000];

void postorder(int l1, int r1, int l2, int r2) {
//    cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
    int root = preorder[l1];
    if (l1 > r1) {
        return;
    }
    if (l1 != r1) {
        for (int i = l2; i <= r2; i++) {
            if (root == inorder[i]) {
                int mid1 = l1 + (i - l2);
                int mid2 = i;
                postorder(l1 + 1, mid1, l2, mid2 - 1);
                postorder(mid1 + 1, r1, mid2 + 1, r2);
                break;
            }
        }
    }
    cout << root << ' ';
}

int main() {
    fastio;
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> preorder[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> inorder[i];
        }
        postorder(0, N - 1, 0, N - 1);
        cout << '\n';
    }
}