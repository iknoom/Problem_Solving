import sys, math, collections
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))

sqrtN = math.sqrt(N)

M = int(input())

query = []
result = [0] * M

for i in range(M):
    l, r = map(int, input().split())
    query.append((l - 1, r - 1, i))

query.sort(key=lambda x : (x[0] // sqrtN, x[1]))

s, e, n = query[0]
Cnt = collections.Counter()
ans = 0
for i in range(s, e + 1):
    Cnt[A[i]] += 1
    if Cnt[A[i]] == 1: ans += 1

result[n] = ans

for si, ei, i in query[1:]:
    while si < s:
        s -= 1
        Cnt[A[s]] += 1
        if Cnt[A[s]] == 1: ans += 1
    while si > s:
        Cnt[A[s]] -= 1
        if not Cnt[A[s]]: ans -= 1
        s += 1
    while ei > e:
        e += 1
        Cnt[A[e]] += 1
        if Cnt[A[e]] == 1: ans += 1
    while ei < e:
        Cnt[A[e]] -= 1
        if not Cnt[A[e]]: ans -= 1
        e -= 1
    result[i] = ans

print(*result, sep='\n')