import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    s = int(input())
    ans = 0

    while s >= 10:
        ans += s - s % 10
        s = s//10 + s % 10
    print(ans + s)