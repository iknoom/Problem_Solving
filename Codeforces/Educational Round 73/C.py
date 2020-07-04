for _ in range(int(input())):
    c, m, x = map(int,input().split())
    if min([c,m,x]) != x:
        print(min([c,m,x]))
    else:
        ans = x
        c -= x
        m -= x
        if c > m : c, m = m, c
        print(ans + min( c , (m+c)//3 ))