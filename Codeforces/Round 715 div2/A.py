from sys import stdin
input = stdin.readline


def solution():
    n = int(input())
    a = list(map(int, input().split()))
    odd = []
    even = []
    for e in a:
        if e % 2:
            odd.append(e)
        else:
            even.append(e)

    answer = odd + even
    print(*answer)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()