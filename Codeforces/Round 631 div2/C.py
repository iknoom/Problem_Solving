N, M = map(int, input().split())
L = list(map(int, input().split()))
ans = []
Sum = sum(L)
if Sum < N:
    print(-1)
else:
    flag = True
    for i in range(M):
        if i + L[i] > N:
            flag = False
    if not flag: print(-1)
    else:
        Over = N - (M - 1 + L[-1])
        cur = 1
        for i in range(M):
            ans.append(cur)
            if Over:
                X = min(Over, L[i] - 1)
                Y = max(0, N - cur - L[i])
                X = min(X, Y)
                cur += X
                Over -= X
            cur += 1
        if not Over:
            print(*ans)
        else:
            print(-1)