#include <iostream>
using namespace std;

int Bx, By, Rx, Ry, Lx, Ly, ans;

int main() {
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
            char t;
            cin >> t;
            if (t == 'B') { Bx = i; By = j; }
            if (t == 'R') { Rx = i; Ry = j; }
            if (t == 'L') { Lx = i; Ly = j; }
        }

    ans = abs(Bx - Lx) + abs(By - Ly) - 1;

    if (Bx == Rx && Rx == Lx) {
        if (By < Ry && Ry < Ly)
            ans = 1 + abs(By - Ly);
        else if (Ry < By && Ly < Ry)
            ans = 1 + abs(By - Ly);
    }

    else if (By == Ry && Ry == Ly) {
        if (Bx < Rx && Rx < Lx)
            ans = 1 + abs(Bx - Lx);
        else if (Lx < Rx && Rx < Bx)
            ans = 1 + abs(Bx - Lx);
    }

    cout << ans << endl;
}