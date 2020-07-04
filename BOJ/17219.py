import sys
input = sys.stdin.readline
N, M = map(int, input().split())
D = {}
for _ in range(N):
    a, b = input().split()
    D[a] = b
for _ in range(M):
    a = input().rstrip()
    print(D[a])