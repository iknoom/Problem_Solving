#include <bits/stdc++.h>

using namespace std;
using pi = pair<long long, string>;

string bfs(long long start, long long target) {
    vector<string> ret;
    queue<pi> q;
    int min_len = 1e9;
    q.push({start, ""});
    while (!q.empty()) {
        auto[u, str] = q.front();
        q.pop();
        if (u == target) {
            if ((int)str.size() < min_len) {
                ret.clear();
                ret.push_back(str);
                min_len = (int)str.size();
            } else if ((int)str.size() == min_len) {
                ret.push_back(str);
            }
            continue;
        }
        if (u != 1 && u * u <= target) {
            q.push({u * u, str + "*"});
        }
        if (u * 2 <= target) {
            q.push({u * 2, str + "+"});
        }
    }
    if (ret.empty()) {
        return "not_found";
    }
    return *min_element(ret.begin(), ret.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long s, t;
    cin >> s >> t;
    // +: * 2
    // -: 0
    // *: ^ 2
    // /: 1
    if (s == t) {
        cout << 0 << '\n';
        return 0;
    }
    if (t == 0) {
        cout << '-' << '\n';
        return 0;
    }
    string answer_from_origin = bfs(s, t);
    string answer_from_one = bfs(1, t);

    if (answer_from_origin == "not_found" && answer_from_one == "not_found") {
        cout << -1 << '\n';
    } else if (answer_from_one == "not_found") {
        cout << answer_from_origin << '\n';
    } else if (answer_from_origin == "not_found") {
        cout << '/' << answer_from_one << '\n';
    } else if ((int)answer_from_origin.size() <= (int)answer_from_one.size() + 1) {
        cout << answer_from_origin << '\n';
    } else {
        cout << '/' << answer_from_one << '\n';
    }
}