import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, x = map(int, input().split())
    s = input().rstrip()
    M = len(s)
    T = []
    p = q = 0
    for i in range(M):
        if s[i] == '0':
            p += 1
        else:
            q += 1
        T.append(p - q)

    X = p - q


    cnt = 0
    if x == 0: cnt += 1

    if X == 0:
        if x in T: print(-1)
        else: print(cnt)
    elif X > 0:
        for t in T:
            k = x - t
            if k >= 0 and k % X == 0:
               cnt += 1
        print(cnt)
    else:
        for t in T:
            k = x - t
            if -k >= 0 and (-k) % (-X) == 0:
               cnt += 1
        print(cnt)
