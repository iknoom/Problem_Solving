N = int(input())
S = input()
T = input()
i, j = map(int, input().split())
a, b = S[i], S[j]
S = S[:i] + S[i+1:j] + S[j+1:]
dp = [[False] * N for _ in range(3)]

for i in range(N - 2):
    if S[i] == T[i]: dp[0][i] = True
    else: break

if T[0] == a:
    dp[1][0] = True

for i in range(1, N - 1):
    if dp[0][i - 1] and T[i] == a: dp[1][i] = True
    if dp[1][i - 1] and T[i] == S[i - 1]: dp[1][i] = True

for i in range(1, N):
    if dp[1][i - 1] and T[i] == b: dp[2][i] = True
    if dp[2][i - 1] and T[i] == S[i - 2]: dp[2][i] = True

print("YES" if dp[2][-1] else "NO")
