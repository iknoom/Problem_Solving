N = int(input())

m = list(map(int, input().split()))
ans = 0

def sol(k):
    ret = l = r = m[k]
    for i in range(k+1, N):
        if m[i] < r: r = m[i]
        ret += r
    for i in range(k-1, -1, -1):
        if m[i] < l: l = m[i]
        ret += l
    return ret
ans_idx = -1
for i in range(N):
    X = sol(i)
    if ans < X:
        ans = X
        ans_idx = i

l = r = m[ans_idx]
for i in range(ans_idx+1, N):
    if m[i] < r:
        r = m[i]
    else:
        m[i] = r
for i in range(ans_idx-1, -1, -1):
        if m[i] < l:
            l = m[i]
        else:
            m[i] = l
print(*m)