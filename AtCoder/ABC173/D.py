import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

A.sort(reverse=True)

dq = deque([])

ans = 0
dq.append(A[0])

for i in range(1, N):
    ans += dq.popleft()
    dq.append(A[i])
    dq.append(A[i])
print(ans)