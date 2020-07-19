import sys, bisect

input = sys.stdin.readline


def solution():
    n, m = map(int, input().split())
    flower = [tuple(map(int, input().split())) for _ in range(m)]
    input()

    flower.sort()
    A = [0]
    dp = [0]
    for i in range(m):
        A.append(flower[i][0])
        dp.append(dp[-1] + flower[i][0])

    answer = dp[-1] - dp[-min(n, m)-1]

    for i in range(m):
        fa, fb = flower[i]
        cur = fa + (n - 1) * fb
        answer = max(answer, cur)

        j = bisect.bisect(A, fb) # larger
        alpha_n = m - j + 1

        if alpha_n > n - 1:
            j += abs(alpha_n - (n - 1))
            alpha_n = n - 1

        alpha = dp[-1] - dp[j - 1]

        if fa > fb:
            alpha_n -= 1
            alpha -= fa
        if alpha_n > 0:
            cur -= fb * alpha_n
            answer = max(answer, cur + alpha)
    print(answer)



if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        solution()