#include <bits/stdc++.h>
using namespace std;

struct shark{
    int s, d, z;
} sharks[10001];
int arr[101][101], tmp[101][101], R, C, M;
long long ans;

long long down(int c) {
    for (int r = 0; r < R; r++){
        if (arr[r][c] != 0){
            int idx = arr[r][c] - 1;
            arr[r][c] = 0;
            return sharks[idx].z;
        }
    }
    return 0;
}

void move() {
    memset(tmp, 0, sizeof(tmp));
    // move to tmp
    for(int c = 0; c < C; c++) for(int r = 0; r < R; r++) {
        if (arr[r][c] == 0) continue;
        int r1, c1, idx, p, q;
        idx = arr[r][c] - 1;

        switch (sharks[idx].d){
            case 1: // up -
                c1 = c;
                r1 = (R - 1) - r + sharks[idx].s;
                p = r1 / (R - 1);
                q = r1 % (R - 1);
                if(p % 2 == 1){
                    sharks[idx].d = 2;
                    r1 = q;
                }
                else {
                    r1 = (R - 1) - q;
                }
                break;
            case 2: // down +
                c1 = c;
                r1 = r + sharks[idx].s;
                p = r1 / (R - 1);
                q = r1 % (R - 1);
                if(p % 2 == 1){
                    sharks[idx].d = 1;
                    r1 = (R - 1) - q;
                }
                else {
                    r1 = q;
                }
                break;
            case 3: // right +
                r1 = r;
                c1 = c + sharks[idx].s;
                p = c1 / (C - 1);
                q = c1 % (C - 1);
                if(p % 2 == 1){
                    sharks[idx].d = 4;
                    c1 = (C - 1) - q;
                }
                else {
                    c1 = q;
                }
                break;
            case 4: // left -
                r1 = r;
                c1 = (C - 1) - c + sharks[idx].s;
                p = c1 / (C - 1);
                q = c1 % (C - 1);
                if(p % 2 == 1){
                    sharks[idx].d = 3;
                    c1 = q;
                }
                else {
                    c1 = (C - 1) - q;
                }
                break;
        }
        if (tmp[r1][c1] == 0) {
            tmp[r1][c1] = idx + 1;
        }
        else if(sharks[tmp[r1][c1] - 1].z < sharks[idx].z){
                tmp[r1][c1] = idx + 1;
        }
    }
    // copy to arr
    for(int c = 0; c < C; c++) for(int r = 0; r < R; r++) {
        arr[r][c] = tmp[r][c];
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> R >> C >> M;
    for(int i = 0; i < M; i++) {
        int r, c;
        cin >> r >> c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
        arr[r - 1][c - 1] = i + 1;
    }
    for(int c_shift = 0; c_shift < C; c_shift++) {
        ans += down(c_shift);
        move();
    }
    cout << ans << '\n';
}