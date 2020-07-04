import sys
input = sys.stdin.readline
N = int(input())
C = [0] * N
for _ in range(N-1):
    a, b = map(int, input().split())
    C[a-1] += 1
    C[b-1] += 1
print(max(C)+1)