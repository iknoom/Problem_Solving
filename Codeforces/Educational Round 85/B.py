import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, x = map(int,input().split())
    A = list(map(int,input().split()))
    A.sort(reverse=True)
    S = 0
    ans = n
    for i in range(n):
        if S + A[i] < x * (i + 1):
            ans = i
            break
        else:
            S += A[i]
    print(ans)
