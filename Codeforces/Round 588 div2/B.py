n, k = map(int,input().split())

if k != 0 and n == 1:
    input()
    print(0)

elif k == 0:
    print(input())
else:
    ans = '1'
    g = input()
    k -= 1

    for q in g[1:]:
        if q != '0' and k:
            ans += '0'
            k -= 1
        else:
            ans += q

    print(ans)

