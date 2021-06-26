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

const int SIZE = 26;
int to_number(char c) { return c - '0'; }

struct Node {
    Node* children[SIZE];
    bool terminal;
    Node() : terminal(false) {
        fill(children, children + SIZE, nullptr);
    }
    ~Node() {
        for (int i = 0; i < SIZE; i++)
            if (children[i]) delete children[i];
    }

    void insert(const char* key) {
        if (*key == '\0') {
            terminal = true;
            return;
        }
        int next = to_number(*key);
        if (!children[next]) children[next] = new Node;
        children[next]->insert(key + 1);
    }

    bool dfs() {
        for (int i = 0; i < SIZE; i++) {
            if (children[i]) {
                if (terminal) return false;
                if (!children[i]->dfs()) return false;
            }
        }
        return true;
    }
};

vector<int> solution() {
    Node *root = new Node;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        root->insert(s.c_str());
    }
    if (root->dfs()) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    delete root;
}

int main() {
    fastio;
    int T;
    cin >> T;
    while (T--) {
        solution();
    }
}