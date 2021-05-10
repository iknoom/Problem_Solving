from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N, Q = map(int, input().split())
    sweep = []
    for i in range(N):
        x1, x2, _ = map(int, input().split())
        sweep.append((x1, x2, i))
    p = [i for i in range(N)]
    before = -1
    before_p = -1
    for x1, x2, x in sorted(sweep):
        if before < x1:
            before = x2
            before_p = p[x]
        else:
            p[x] = before_p
            before = max(before, x2)
    for _ in range(Q):
        x, y = map(int, input().split())
        if p[x - 1] == p[y - 1]:
            print(1)
        else:
            print(0)