N, M = map(int, input().split())
P = list(map(int, input().split()))
X = list(map(int, input().split()))

end_point = P[0] + X[0]
cnt = 0
i = 1
while i < N:
    if M <= end_point:
        break
    tmp = -1
    while i < N and P[i] <= end_point:
        tmp = max(tmp, P[i] + X[i])
        i += 1
    if tmp == -1:
        break
    end_point = tmp
    cnt += 1

if M <= end_point:
    print(cnt)
else:
    print(-1)