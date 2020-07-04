import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N, X = map(int,input().split())
    A = set(map(int,input().split()))
    ans = 1
    while X:
        if ans not in A:
            X -= 1
        if not X: break
        ans += 1

    while ans + 1 in A:
        ans += 1
    print(ans)
