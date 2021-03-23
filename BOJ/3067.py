from sys import stdin
input = stdin.readline

def solution(N, V, M):
    dp = [1] + [0] * M
    for v in V:
        for i in range(1, M + 1):
            if i - v < 0: continue
            dp[i] += dp[i - v]
    return dp[-1]

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        N = int(input())
        V = list(map(int, input().split()))
        M = int(input())
        answer = solution(N, V, M)
        print(answer)