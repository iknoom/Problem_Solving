import sys

input = sys.stdin.readline


def solution():
    n, m = map(int, input().split())
    ans = m
    digx = [-1] * n
    digy = [-1] * n
    for _ in range(m):
        x, y = map(int, input().split()) # rook
        x -= 1
        y -= 1
        if x == y:
            ans -= 1
            continue
        digx[x] = y
        digy[y] = x
    vst = [False] * n
    for i in range(n):
        if vst[i]: continue
        if digx[i] == -1: continue
        if digy[i] == -1: continue
        u = i
        while True:
            if vst[u]: break
            vst[u] = True
            if digy[u] == -1:
                break
            u = digy[u]
        if u == i:
            ans += 1
    print(ans)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()