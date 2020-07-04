N = int(input())
A = sorted(map(int, input().split())) + [10**18]

def find_less(l, r, k):
    mid = -1
    while l + 1 < r:
        mid = (l + r) // 2
        if A[mid] <= k: l = mid
        else: r = mid
    return l

def find_more(l, r, k):
    mid = -1
    while l + 1 < r:
        mid = (l + r) // 2
        if A[mid] >= k: r = mid
        else: l = mid
    return r

ans = 10**18
ret = []

for i in range(N - 1):
    k = A[i]
    A[i] = -10**18
    x = find_less(i, N, -k)
    y = find_more(i, N, -k)
    if x != i and abs(k + A[x]) < ans:
        ans = abs(k + A[x])
        ret = [k, A[x]]
    if y != N and abs(k + A[y]) < ans:
        ans = abs(k + A[y])
        ret = [k, A[y]]

print(*sorted(ret))