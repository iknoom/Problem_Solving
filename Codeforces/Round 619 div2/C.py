import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n, m = list(map(int, input().split()))
    S = 0
    x = (n - m) // (m + 1)
    z = (n - m) % (m + 1)

    S += (m + 1 - z) * (x * (x + 1)) // 2
    S += z * (x + 1) * (x + 2) // 2
    print(n * (n + 1) // 2 - S)