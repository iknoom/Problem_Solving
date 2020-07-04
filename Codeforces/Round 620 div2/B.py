n, m = map(int, input().split())
K = list(set(input() for _ in range(n)))
n = len(K)

def is_pal(S):
    global m
    ret = True
    for i in range(m//2+1):
        if S[i] != S[-i-1]:
            ret = False
    return ret

ans = ""

for k in K:
    if is_pal(k):
        ans = k
        break

for i in range(n - 1):
    for j in range(i + 1, n):
        if K[i] == K[j][::-1]:
            ans = K[i] + ans + K[j]
            break

print(len(ans))
print(ans)