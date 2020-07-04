import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, p, k = map(int,input().split())
    A = list(map(int,input().split()))
    A.sort()
    q = p

    ans = 0
    i = k - 1
    while(i < n):
        if A[i] <= p:
            ans += k
            p -= A[i]
        else:
            break
        i += k

    ans2 = 0
    if A[0] <= q:
        ans2 += 1
        q -= A[0]
        i = k
        while (i < n):
            if A[i] <= p:
                ans += k
                p -= A[i]
            else:
                break
            i += k

    print(max(ans, ans2))