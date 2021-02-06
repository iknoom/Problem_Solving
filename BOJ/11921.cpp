#include <bits/stdc++.h>

using namespace std;
int N, L;
long long S;
char buf[1 << 17];

char read() {
    static int idx = 1 << 17;
    if (idx == 1 << 17) {
        fread(buf, 1, 1 << 17, stdin);
        idx = 0;
    }
    return buf[idx++];
}

int readInt() {
    int ret = 0;
    char now = read();
    while (now == 10 || now == 32) now = read();
    while (now >= 48 && now <= 57) {
        ret = ret * 10 + now - 48;
        now = read();
    }
    return ret;
}

int main() {
    N = readInt();
    for (int i = 0; i < N; i++) {
        L = readInt();
        S += (long long)L;
    }
    printf("%lld\n%lld\n", N, S);
}