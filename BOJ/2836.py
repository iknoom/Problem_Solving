from sys import stdin
input = stdin.readline

if __name__ == '__main__':
    N, M = map(int, input().split())
    sweep = []
    for _ in range(N):
        a, b = map(int, input().split())
        if a > b:
            sweep.append((b, a))
    sweep.sort()
    answer = M
    before = -1
    for a, b in sweep:
        if before < a:
            answer += 2 * (b - a)
        else:
            answer += 2 * max(0, b - before)
        before = max(before, b)
    print(answer)