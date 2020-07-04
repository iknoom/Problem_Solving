#include <iostream>
#include <string>
using namespace std;

int T, N;

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string A, B;
        int ans = 0;
        cin >> N;
        cin >> A >> B;
        for (int i = 0; i < N; i++) {
            if (A[i] == B[i]) ans++;
        }
        cout << "#" << t << " " << ans << endl;
    }
}