import sys
input = sys.stdin.readline

N, X, K = map(int, input().split())
cup = [0] * N
cup[X - 1] = 1
for _ in range(K):
    a, b = map(int, input().split())
    a -= 1; b -= 1
    cup[a], cup[b] = cup[b], cup[a]
for i in range(N):
    if cup[i]:
        print(i + 1)