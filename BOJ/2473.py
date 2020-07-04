N = int(input())
A = sorted(map(int, input().split())) + [10**18]

def find_less(l, r, k):
    while l + 1 < r:
        mid = (l + r) // 2
        if A[mid] <= k: l = mid
        else: r = mid
    return l

def find_more(l, r, k):
    while l + 1 < r:
        mid = (l + r) // 2
        if A[mid] >= k: r = mid
        else: l = mid
    return r

ans = 10**18
ret = []

for i in range(N - 2):
    a = A[i]
    for j in range(i + 1, N - 1):
        b = A[j]
        A[j] = -10**18
        x = find_less(j, N, -a-b)
        y = find_more(j, N, -a-b)
        if x != j and abs(a + b + A[x]) < ans:
            ans = abs(a + b + A[x])
            ret = [a, b, A[x]]
        if y != N and abs(a + b + A[y]) < ans:
            ans = abs(a + b + A[y])
            ret = [a, b, A[y]]
        A[j] = b

print(*sorted(ret))