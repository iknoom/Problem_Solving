from sys import stdin
input = stdin.readline


def solution():
    n = int(input())
    a = list(map(int, input().split()))

    if a[-1] == 0:
        print(*range(1, n + 2))
        return

    if a[0] == 1:
        answer = [n + 1] + list(range(1, n + 1))
        print(*answer)
        return

    for i in range(n - 1):
        if a[i] == 0 and a[i + 1] == 1:
            answer = list(range(1, i + 1)) + [i + 1, n + 1, i + 2] + list(range(i + 3, n + 1))
            print(*answer)
            return
    print(-1)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()