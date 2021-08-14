#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define x first
#define y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;

bool is_win(char a, char b) {
    if (a == 'R' && b == 'S') {
        return true;
    } else if (a == 'S' && b == 'P') {
        return true;
    } else if (a == 'P' && b == 'R'){
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, T;
    cin >> N >> T;
    string all_str;
    cin >> all_str;

    char cur_c = all_str[0];
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (cur_c == all_str[i]) {
            cnt++;
        } else if (is_win(cur_c, all_str[i])){
            int diff = min(cnt, T);
            swap(all_str[i], all_str[i - diff]);
            cnt = diff;
        } else {
            cur_c = all_str[i];
            cnt = 1;
        }
    }
    cout << all_str;
}