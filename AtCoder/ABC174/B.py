import sys, math
input = sys.stdin.readline

N, D = map(int, input().split())
ans = 0
for _ in range(N):
    x, y = map(int, input().split())
    if x * x + y * y <= D * D:
        ans += 1

print(ans)