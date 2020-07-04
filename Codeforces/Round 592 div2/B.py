import sys
input = sys.stdin.readline


for _ in range(int(input())):
    N = int(input())
    g = list(map(int, input().rstrip()))
    ans = N
    for i in range(N):
        if g[i]:
            k = max(i+1, N-i)
            ans = max(ans, k*2)
    print(ans)