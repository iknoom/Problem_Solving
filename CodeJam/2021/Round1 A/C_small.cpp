#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;
using pi = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int gcd(int a, int b){

    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

void solution() {
    int N, Q;
    cin >> N >> Q;
    vector<string> Answers(N);
    vector<int> Points(N);
    for (int i = 0; i < N; i++) {
        cin >> Answers[i] >> Points[i];
    }
    vector<string> predicts;
    for (int i = 0; i < (1 << Q); i++) {
        string cur;
        for (int j = 0; j < Q; j++) {
            if (i & (1 << j)) cur.push_back('T');
            else cur.push_back('F');
        }
        bool flag = true;
        for (int i = 0; i < N; i++) {
            int p = 0;
            for (int j = 0; j < Q; j++) {
                if (cur[j] == Answers[i][j]) p++;
            }
            if (p != Points[i]) {
                flag = false;
            }
        }
        if (flag) {
            predicts.push_back(cur);
        }
    }

    // eval max
    int max_count = 0;
    string answer;

    for (int i = 0; i < (1 << Q); i++) {
        string cur;
        for (int j = 0; j < Q; j++) {
            if (i & (1 << j)) cur.push_back('T');
            else cur.push_back('F');
        }

        int S = 0;
        for (auto predict : predicts) {
            for (int k = 0; k < Q; k++) {
                if (predict[k] == cur[k]) S++;
            }
        }
        if (max_count < S) {
            max_count = S;
            answer = cur;
        }
    }
    int z = max_count, w = predicts.size();
    cout << answer << ' ' << z/gcd(z,w) << '/' << w/gcd(z,w) << '\n';
}

int main() {
    fastio;
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        cout << "Case #" << c << ": ";
        solution();
    }
}