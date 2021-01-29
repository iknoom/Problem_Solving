import sys
input = sys.stdin.readline


def solution():
    n = int(input())
    LR = input().rstrip()
    left = [0] * (n + 1)
    right = [0] * (n + 1)

    S = 0
    before = "-"
    for i in range(n):
        if LR[i] == 'L':
            if before == 'R':
                S += 1
            else:
                S = 1
            left[i + 1] = S
        elif LR[i] == 'R':
            if before == 'L':
                S += 1
            else:
                S = 1
        before = LR[i]

    S = 0
    before = "-"
    for i in range(n - 1, -1, -1):
        if LR[i] == 'R':
            if before == 'L':
                S += 1
            else:
                S = 1
            right[i] = S
        elif LR[i] == 'L':
            if before == 'R':
                S += 1
            else:
                S = 1
        before = LR[i]

    for i in range(n + 1):
        # print(left[i], right[i])
        print(1 + left[i] + right[i], end=' ')
    print()

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()