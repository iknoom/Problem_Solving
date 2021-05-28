from sys import stdin
input = stdin.readline


def solution():
    n = int(input())
    A = sorted(map(int, input().split()))
    answer = []
    for i in range(n):
        answer.append(A[i])
        answer.append(A[n + i])
    print(*answer)

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()