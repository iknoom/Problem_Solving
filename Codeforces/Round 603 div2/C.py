from math import sqrt
for _ in range(int(input())):
    N = int(input())

    ans = set()
    ans.add(0)
    for i in range(1, int(sqrt(N))+3):
        p = N // i
        if p:
            ans.add(p)
            ans.add(N//p)
    print(len(ans))
    print(*sorted(ans))