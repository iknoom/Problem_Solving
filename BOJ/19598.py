from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    sweep = []
    ans = 0

    N = int(input())
    for _ in range(N):
        s, e = map(int, input().split())
        sweep += [(s, 1), (e, -1)]
    sweep.sort()

    cur = 0
    for _, t in sweep:
        cur += t
        ans = max(ans, cur)

    print(ans)