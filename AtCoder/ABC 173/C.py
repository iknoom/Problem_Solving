import sys
input = sys.stdin.readline

H, W, K = map(int, input().split())

B = [input().rstrip() for _ in range(H)]


def get_black(X, Y):
    ret = 0
    for i in range(W):
        for j in range(H):
            if i in X or j in Y: continue
            if B[j][i] == '#': ret += 1
    return ret

ans = 0

for i in range(1 << W):
    for j in range(1 << H):
        X = set()
        Y = set()
        for x in range(W):
            if (1 << x) & i: X.add(x)
        for y in range(H):
            if (1 << y) & j: Y.add(y)

        if get_black(X, Y) == K:
            ans += 1
print(ans)