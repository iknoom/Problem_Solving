from sys import stdin
input = stdin.readline
MOD = 2 ** 64

def solution(M, N, candy):
    candy.sort(reverse=True)
    candy.append(0)
    for i in range(1, N + 1):
        D = (candy[i - 1] - candy[i]) * i
        if D >= M:
            angry = 0
            height = candy[i - 1] - (M // i)
            M %= i
            angry += height ** 2 * (i - M)
            angry += (height - 1) ** 2 * M
            angry %= MOD
            for j in range(i, N):
                angry += candy[j] ** 2
                angry %= MOD
            return angry
        else:
            M -= D

if __name__ == '__main__':
    M, N = map(int, input().split())
    candy = [int(input()) for _ in range(N)]
    answer = solution(M, N, candy)
    print(answer)
