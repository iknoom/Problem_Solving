for _ in range(int(input())):
    N = int(input())
    card = {}
    t = []
    for i in range(N):
        q = input()
        if q not in card:
            card[q] = 1
        else:card[q] += 1
        t.append(q)
    cnt = 0
    for i in range(N):
        if card[t[i]] == 1:
            continue
        if card[t[i]] > 1:
            card[t[i]] -= 1
            cnt += 1
        for x in range(4):
            flag = False
            c = list(t[i])
            for y in range(0,10):
                c[x] = str(y)
                new = ''.join(c)
                if new not in card:
                    card[new] = 1
                    t[i] = new
                    flag = True
                    break
            if flag: break
    print(cnt)
    print(*t,sep='\n')

