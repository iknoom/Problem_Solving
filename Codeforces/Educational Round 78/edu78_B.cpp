#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t;

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> t;
    vector<int> S;
    long long k = 0;
    int i = 0;
    while(k <= 2e9){
        S.push_back(k);
        i++;
        k += i;
    }
    while(t--){
        int a, b;
        cin >> a >> b;
        int diff = abs(b - a);
        auto idx = lower_bound(S.begin(), S.end(), diff) - S.begin();

        diff = S[idx] - diff;
        if (diff & 1) {
            if (idx & 1)
                cout << idx + 2 << '\n';
            else
                cout << idx + 1 << '\n';
        }
        else {
            cout << idx << '\n';
        }
    }
}

