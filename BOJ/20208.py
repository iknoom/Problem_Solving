from itertools import permutations as per

N, M, H = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(N)]
house = [(i, j) for i in range(N) for j in range(N) if B[i][j] == 1]
milk = [(i, j) for i in range(N) for j in range(N) if B[i][j] == 2]


def sol(p):
    h = M
    cnt = 0
    ans = 0
    x, y = p[0]
    for i in range(len(p) - 1):
        x0, y0 = p[i]
        x1, y1 = p[i + 1]
        dist = abs(x0 - x1) + abs(y0 - y1)
        if h >= dist:
            h -= dist
            h += H
            cnt += 1
        else:
            break
        if h >= abs(x - x1) + abs(y - y1):
            ans = cnt
    return ans

print(max(sol(house + list(p)) for p in per(milk)))