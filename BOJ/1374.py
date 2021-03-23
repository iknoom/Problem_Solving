from sys import stdin
input = stdin.readline


def main():
    N = int(input())
    sweep = []
    for i in range(N):
        _, a, b = map(int, input().split())
        sweep.append((a, 1))
        sweep.append((b, -1))

    answer = 0
    cur = 0
    for ab, inc in sorted(sweep):
        cur += inc
        answer = max(answer, cur)
    print(answer)

if __name__ == '__main__':
    main()