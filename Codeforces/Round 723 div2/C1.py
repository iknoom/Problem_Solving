from sys import stdin
input = stdin.readline


def solution():
    n = int(input())
    a = list(map(int, input().split()))
    dp = [-1] * (n + 1)
    dp[0] = 0
    for k in a:
        dp2 = dp[:]
        for i in range(n):
            if dp[i] >= 0 and dp[i] + k >= 0:
                dp2[i + 1] = max(dp2[i + 1], dp[i] + k)
        dp = dp2
    answer = -1
    for i in range(n + 1):
        if dp[i] >= 0:
            answer = i
    print(answer)


if __name__ == '__main__':
    solution()