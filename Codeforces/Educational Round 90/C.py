import sys
input = sys.stdin.readline
INF = 10**9

T = int(input())

for _ in range(T):
    S = input().rstrip()
    N = len(S)
    min_index = [INF] * (N + 5)
    k = 0
    for i in range(N):
        if S[i] == '+':
            k += 1
        else:
            k -= 1
        if k < 0:
            min_index[-k] = min(min_index[-k], i)
    ans = N
    for i in range(N):
        if min_index[i + 1] == INF:
            break
        else:
            ans += min_index[i + 1] + 1
    print(ans)