for _ in range(int(input())):
    N = int(input())
    num = list(map(int, input().split()))
    num.sort(reverse=True)
    x = 0
    ans = 'NO'
    for k in num:
        if k > 2048: continue
        else: x += k
        if x == 2048: ans = 'YES'
    print(ans)