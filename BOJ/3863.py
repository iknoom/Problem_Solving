from sys import stdin
input = stdin.readline

while True:
    N, M = map(int, input().split())
    if N + M == 0:
        break
    tel = [tuple(map(int, input().split())) for _ in range(N)]
    lr = [tuple(map(int, input().split())) for _ in range(M)]
    for i in range(M):
        l, r = lr[i]
        r += l
        S = 0
        for _, _, a, b in tel:
            b += a
            if r <= a or b <= l:
                continue
            S += 1
        print(S)