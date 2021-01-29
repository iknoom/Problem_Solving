import sys
input = sys.stdin.readline

def solution():
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    answer = 0
    S = p[0]
    for i in range(1, n):
        if S * k < p[i] * 100:
            cur = 0
            U = 100 * p[i] - k * S
            if U % k == 0:
                cur = U // k
            else:
                cur = U // k + 1
            answer = max(answer, cur)
        S += p[i]
    print(answer)


if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()