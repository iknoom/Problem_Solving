#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    string A, B;
    cin >> t;
    while (t--) {
        cin >> A >> B;
        int L1 = A.size();
        int L2 = B.size();
        if (L1 > L2) {
            cout << "NO" << endl;
        }
        else {
            string ans = "NO";
            for (int i = 0; i <= L2 - L1; i++) {
                vector<int> v1(26);
                for (int q = 0; q < 26; q++) {
                    v1[q] = 0;
                }
                for (int c : A) {
                    v1[c - 97] += 1;
                }
                for (int j = i; j < i + L1; j++) {
                    v1[B[j] - 97] -= 1;
                }
                bool z = true;
                for (int q = 0; q < 26; q++) {
                    if (v1[q] != 0) z = false;
                }
                if (z) ans = "YES";
            }
            cout << ans << endl;
        }
    }

}

