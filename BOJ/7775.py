N, p, k, d = map(int, input().split())

# 1. p == 0
# 모두 0이 되도록
if p == 0:
    if d > 1:
        print("Wrong information")
    else:
        for _ in range(N):
            print(0)

# 2. d == 1
# 점수가 같은 k명이 상위가 되도록
elif d == 1:
    ans = [p // k] * k
    p -= (p // k) * k
    if k != N:
        M = N - k
        ans += [p // M] * M
        p -= (p // M) * M
        for i in range(k, N):
            if not p: break
            ans[i] += 1
            p -= 1
        if ans[k - 1] < ans[k]:
            print("Wrong information")
        else:
            print(*ans, sep='\n')
    else:
        if p:
            print("Wrong information")
        else:
            print(*ans, sep='\n')

# p > 0 and d > 1
# 서로 다른 d명이 있도록
elif d * (d-1) // 2 > p:
    print("Wrong information")
else:
    r = p - (d * (d-1) // 2)
    for i in range(d):
        if i == 0:
            print(d - i - 1 + r)
        else:
            print(d - i - 1)
    for i in range(N - d):
        print(0)