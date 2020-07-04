import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    a, b, n, m = map(int, input().split())
    if min(a, b) < m:
        print("No")
    elif a + b < n + m:
        print("No")
    else:
        print("Yes")
