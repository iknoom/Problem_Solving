#include <bits/stdc++.h>

using namespace std;

int mapping(string s) {
    if (s == "-") return 0;
    if (s == "and") return 0;

    if (s == "cpp") return 1;
    if (s == "java") return 2;
    if (s == "python") return 3;

    if (s == "backend") return 10;
    if (s == "frontend") return 20;

    if (s == "junior") return 100;
    if (s == "senior") return 200;

    if (s == "chicken") return 1000;
    if (s == "pizza") return 2000;

    return -1;
}
vector<string> split(string str) {
    vector<string> ret;
    stringstream stream(str);
    string tmp;
    while (getline(stream, tmp, ' '))
        ret.push_back(tmp);
    return ret;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> dp[2300];
    int is_sorted[2300] = {0};
    // fill dp
    for (auto s : info) {
        int curr = 0, point = 0;
        for (auto sub_s : split(s)) {
            int tmp = mapping(sub_s);
            if (tmp < 0) {
                point = stoi(sub_s);
            } else {
                curr += tmp;
            }
        }
        int diff[] = {1, 10, 100, 1000};
        for (int i = 0; i < (1 << 4); i++) {
            vector<int> diffs;
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) diffs.push_back(diff[j]);
            }
            int total = curr;
            for (auto k : diffs) {
                total -= ((total/k) % 10) * k;
            }
            cout << total << '\n';
            dp[total].push_back(point);
        }
    }
    cout << '\n';
    // do query
    for (auto q : query) {
        int curr = 0, point = 0;
        for (auto sub_s : split(q)) {
            int tmp = mapping(sub_s);
            if (tmp < 0) {
                point = stoi(sub_s);
            } else {
                curr += tmp;
            }
        }

        if (is_sorted[curr] == 0) {
            sort(dp[curr].begin(), dp[curr].end());
            is_sorted[curr] = 1;
        }

        auto lower = lower_bound(dp[curr].begin(), dp[curr].end(), point);
        answer.push_back(dp[curr].end() - lower);
    }
    return answer;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    solution(info, query);
}