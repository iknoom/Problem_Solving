import sys
input = sys.stdin.readline



N = int(input())
A = list(map(int, input().split()))

ans = 0

for i in range(N):
    if (i % 2 == 0) and (A[i] % 2 == 1):
        ans += 1

print(ans)