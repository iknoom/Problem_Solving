import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, p, _ = map(int,input().split())
    A = list(map(int,input().split()))
    A.sort()

    ans = 0
    q = p
    for i in range(n//2):
        if A[i*2 + 1] <= q:
            ans += 2
            q -= A[i*2 + 1]
        elif A[i*2] <= q:
            ans += 1
            q -= A[i*2]
            break
    if n&1 and A[-1] <= q:
        ans += 1

    ans2 = 0
    if p >= A[0]:
        ans2 += 1
        p -= A[0]
        i = 2
        while(i < n):
            if A[i] <= p:
                ans2 += 2
                p -= A[i]
            elif A[i-1] <= p:
                ans2 += 1
                p -= A[i-1]
                break
            i += 2
        if n&1 == 0 and A[-1] <= p:
            ans2 += 1


    print(max(ans, ans2))