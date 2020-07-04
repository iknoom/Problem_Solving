import sys

N = int(input())
A = list(map(int, input().split()))

stack = []
for i in range(N):
    M = A[i]
    cnt = 1
    while stack and stack[-1][0] * cnt > M * stack[-1][1]:
        x, y = stack.pop()
        M += x
        cnt += y
    stack.append((M, cnt))

for k in stack:
    for _ in range(k[1]):
        sys.stdout.write(format(k[0] / k[1], "0.9f") + '\n')