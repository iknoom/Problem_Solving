import sys

input = sys.stdin.readline


def solution():
    S = list(input().rstrip())
    n = len(S)
    ans = 0
    for i in range(1, n):
        if S[i] == S[i - 1]:
            S[i] = '-'
            ans += 1
        elif i > 1 and S[i] == S[i - 2]:
            S[i] = '-'
            ans += 1
    print(ans)

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()