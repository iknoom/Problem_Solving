#include<bits/stdc++.h>

using namespace std;
typedef long long Long;

Long w, h, L;

Long f(Long R, Long limit) {
    Long ret = 0;
    for (Long x = 1; x < limit; x++) {
        Long l = 0, r = 300000;
        while (l + 1 < r) {
            Long mid = (l + r) / 2;
            if (x * x + mid * mid <= R * R) {
                l = mid;
            } else {
                r = mid;
            }
        }
        ret += l;
    }

    return ret;
}

bool check(Long x, Long y) {
    return ((w + y) * (w + y) + x * x <= (L - h) * (L - h)) || (y * y + (h + x) * (h + x) <= (L - w) * (L - w));
}

int main() {
    cin >> w >> h >> L;
    Long answer = f(L, L) * 3 + 2 * L;
    if (L - h > 0) {
        answer += f(L - h, min(L - h, w)) + (L - h);
    }
    if (L - w > 0) {
        answer += f(L - w, min(L - w, h)) + (L - w);
    }
    if (L - w - h > 0) {
        for (Long x = 0; x <= L; x++) {
            if (!check(x, 0)) break;
            Long l = 0, r = 500000;
            while (l + 1 < r) {
                Long mid = (l + r) / 2;
                if (check(x, mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            answer += l + 1;
        }
        answer -= 1;
    }
    cout << answer << '\n';
}