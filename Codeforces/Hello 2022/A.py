import sys

input = sys.stdin.readline


def solution():
    n, k = map(int, input().split())
    if k * 2 - 1 > n:
        print(-1)
        return
    answer = [['.'] * n for _ in range(n)]
    for i in range(k):
        answer[i * 2][i * 2] = 'R'
    for row in answer:
        print(''.join(row))

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()