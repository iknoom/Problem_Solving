import sys

input = sys.stdin.readline


def solution():
    n = int(input())
    S = input().rstrip()
    cnt = 0
    for i in range(n):
        if S[-i - 1] == ')':
            cnt += 1
        else:
            break
    r = n - cnt
    if r < cnt:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()