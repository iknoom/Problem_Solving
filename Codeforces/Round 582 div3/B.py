T = int(input())

for _ in range(T):
    N = int(input())
    min_p = 10**10
    ans = 0
    for i in list(map(int,input().split()))[::-1]:
        if i < min_p:
            min_p = i
        elif i > min_p:
            ans += 1
    print(ans)