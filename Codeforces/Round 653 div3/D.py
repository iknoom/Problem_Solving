import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    count = {}
    for i in range(n):
        A[i] %= k

    for i in range(n):
        if A[i] == 0: continue
        t = k - A[i]
        if t in count:
            count[t] += 1
        else:
            count[t] = 1
    ans = 0
    for c in count:
        ans = max(ans, c + (count[c] - 1) * k + 1)
    print(ans)




