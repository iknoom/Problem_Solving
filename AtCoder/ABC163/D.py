import sys
input = sys.stdin.readline
N, K = map(int, input().split())
MOD = 10**9 + 7
ans = 0

for i in range(K, N + 2):
    p = 0 + i - 1
    q = N - i + 1
    P = p * (p + 1) // 2
    Q = P + (i * q)
    ans += Q - P + 1
    ans %= MOD
print(ans)


