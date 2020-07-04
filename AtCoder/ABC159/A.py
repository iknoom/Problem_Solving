import sys
input = sys.stdin.readline

N, M = map(int, input().split())
a = N * (N - 1) // 2
b = M * (M - 1) // 2

print(a + b)