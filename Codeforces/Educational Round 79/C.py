import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n, m = map(int,input().split())
    A = list(map(int,input().split()))
    B = list(map(int, input().split()))
    ans = 0

    idx = [0] * (n+1)
    vst = [False] * n

    for i in range(n):
        idx[A[i]] = i

    midx = -1
    cnt = 0
    for b in B:
        if idx[b] < midx:
            ans += 1
        else:
            ans += (idx[b] - cnt) * 2 + 1
            midx = idx[b]
        cnt += 1
    print(ans)



