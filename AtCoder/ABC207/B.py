A, x, y, D = map(int, input().split())
if D * y - x <= 0:
    print(-1)
else:
    r = D * y - x
    answer = A // r
    if A % r:
        answer += 1
    print(answer)