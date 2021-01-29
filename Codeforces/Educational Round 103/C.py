import sys
input = sys.stdin.readline


def solution():
    n = int(input())
    c = list(map(int, input().split()))
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    answer = 0
    S = c[-1] - 1
    for i in range(n - 1, 0, -1):
        S += 2
        answer = max(answer, S + abs(a[i] - b[i]))
        if a[i] == b[i]:
            S = c[i - 1] - 1
        else:
            S = max(S + (c[i - 1] - 1) - abs(a[i] - b[i]), c[i - 1] - 1)
    print(answer)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()