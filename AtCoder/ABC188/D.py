from sys import stdin

input = stdin.readline

if __name__ == "__main__":
    N, C = map(int, input().split())

    sweep = []
    for _ in range(N):
        a, b, c = map(int, input().split())
        sweep.append((a, c))
        sweep.append((b + 1, -c))
    sweep.sort()

    ans = 0
    cur = 0
    before = 1
    for ab, c in sweep:
        ans += (ab - before) * min(C, cur)
        cur += c
        before = ab
    print(ans)


