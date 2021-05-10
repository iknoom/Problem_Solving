from sys import stdin
input = stdin.readline


def solution():
    N = int(input())
    count = [int(input()) for _ in range(N)]
    S = sum(count)
    max_value = max(count)
    C = []
    for i in range(N):
        if count[i] == max_value:
            C.append(i)
    if len(C) > 1:
        print("no winner")
    elif max_value * 2 > S:
        print("majority winner", C[0] + 1)
    else:
        print("minority winner", C[0] + 1)


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        solution()