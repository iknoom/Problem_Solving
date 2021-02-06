from sys import stdin
input = stdin.readline
T = int(input())
for _ in range(T):
    P, M, F, C = map(int, input().split())
    if P > M:
        print(0)
        continue
    cpn = (M // P) * C
    cpn = (cpn // F) * C + (cpn % F)
    d = F - C

    ans = cpn // d
    cpn %= d
    ans -= (F - cpn) // d

    while cpn + d < F:
        ans -= 1
        cpn += d
    print(ans)