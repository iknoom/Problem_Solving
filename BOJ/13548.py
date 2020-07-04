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
Cnt = collections.Counter(A[s:e+1])
Cnt_Cnt = collections.Counter(Cnt.values())
Max_Cnt = max(Cnt.values())
result[n] = Max_Cnt

for si, ei, i in query[1:]:
    while si < s:
        s -= 1
        Cnt_Cnt[Cnt[A[s]]] -= 1
        Cnt[A[s]] += 1
        Cnt_Cnt[Cnt[A[s]]] += 1
        Max_Cnt = max(Max_Cnt, Cnt[A[s]])

    while ei > e:
        e += 1
        Cnt_Cnt[Cnt[A[e]]] -= 1
        Cnt[A[e]] += 1
        Cnt_Cnt[Cnt[A[e]]] += 1
        Max_Cnt = max(Max_Cnt, Cnt[A[e]])

    while si > s:
        Cnt_Cnt[Cnt[A[s]]] -= 1
        Cnt[A[s]] -= 1
        Cnt_Cnt[Cnt[A[s]]] += 1
        s += 1

    while ei < e:
        Cnt_Cnt[Cnt[A[e]]] -= 1
        Cnt[A[e]] -= 1
        Cnt_Cnt[Cnt[A[e]]] += 1
        e -= 1

    while Cnt_Cnt[Max_Cnt] == 0: Max_Cnt -= 1
    result[i] = Max_Cnt

print(*result, sep='\n')