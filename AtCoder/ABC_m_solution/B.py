import sys
input = sys.stdin.readline

A, B, C = map(int, input().split())

K = int(input())

cnt = 0

while A >= B:
    B *= 2
    cnt += 1

while B >= C:
    C *= 2
    cnt += 1

if cnt > K:
    print("No")
else:
    print("Yes")