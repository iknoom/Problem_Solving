import sys

input = sys.stdin.readline


def solution():
    S = input().rstrip()
    if len(S) % 2 == 1:
        return False
    if S[0] == ')':
        return False
    if S[-1] == '(':
        return False
    return True


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        if solution():
            print("YES")
        else:
            print("NO")