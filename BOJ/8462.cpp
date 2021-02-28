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

struct Query {
    static int sqrtN;
    int start, end, index;

    bool operator<(const Query& q) const {
        if (start / sqrtN != q.start / sqrtN)
            return start / sqrtN < q.start / sqrtN;
        else return end < q.end;
    }
};

int Query::sqrtN = 0;

vector<long long> mosAlg(vector<long long>& arr, vector<Query>& queries) {
    Query::sqrtN = sqrt(arr.size());
    sort(queries.begin(), queries.end());

    vector<long long> count(*max_element(arr.begin(), arr.end()) + 1);
    vector<long long> answer(queries.size());
    long long currPower = 0;
    int start = queries[0].start, end = queries[0].end;
    for (int i = start; i < end; i++) {
        count[arr[i]]++;
        currPower += (2 * count[arr[i]] - 1) * arr[i];
    }
    answer[queries[0].index] = currPower;
    for (int i = 1; i < queries.size(); i++) {
        while (queries[i].start < start) {
            start--;
            count[arr[start]]++;
            currPower += (2 * count[arr[start]] - 1) * arr[start];
        }
        while (end < queries[i].end) {
            count[arr[end]]++;
            currPower += (2 * count[arr[end]] - 1) * arr[end];
            end++;
        }
        while (start < queries[i].start) {
            currPower -= (2 * count[arr[start]] - 1) * arr[start];
            count[arr[start]]--;
            start++;
        }
        while (queries[i].end < end) {
            end--;
            currPower -= (2 * count[arr[end]] - 1) * arr[end];
            count[arr[end]]--;
        }
        answer[queries[i].index] = currPower;
    }
    return answer;
}

int main() {
    fastio;
    int n, t;
    cin >> n >> t;
    vector<long long> arr(n);
    vector<Query> queries(t);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < t; i++) {
        cin >> queries[i].start >> queries[i].end;
        queries[i].start--;
        queries[i].index = i;
    }
    vector<long long> answer = mosAlg(arr, queries);
    for (auto k : answer) {
        cout << k << '\n';
    }
}