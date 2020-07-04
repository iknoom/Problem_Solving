#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int N;
vector<pi> v;
vector<pi> stack;

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());

    for (auto p : v) {
        while (!stack.empty() && (p.first - stack.back().first) <= (p.second - stack.back().second))
            stack.pop_back();
        if (stack.empty() || (p.first - stack.back().first) > (stack.back().second - p.second))
            stack.push_back(p);
    }
    cout << stack.size() << endl;
}