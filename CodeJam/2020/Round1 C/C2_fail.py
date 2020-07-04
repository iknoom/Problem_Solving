import sys
input = sys.stdin.readline

T = int(input())
INF = 10**9

def solve(W):
    ret = INF
    cur_cnt = 0
    m_cutting = 0
    bigger = 0
    for j in range(N):
        X, Y = A[j] // W, A[j] % W
        if Y != 0:
            bigger += X
        else:
            if cur_cnt + X <= D:
                m_cutting += 1
                cur_cnt += X
            else:
                bigger += X

        if cur_cnt + bigger >= D:
            ret = min(ret, D - m_cutting)
    return ret

for case in range(1, T + 1):
    N, D = map(int, input().split())
    A = list(map(int, input().split()))

    NUMS = set()

    for a in A:
        for i in range(1, D + 1):
            if a % i == 0: NUMS.add(a//i)
    NUMS = sorted(NUMS, reverse=True)

    ans = D - 1
    L = 0
    R = len(NUMS) - 1
    while L + 1 < R:
        mid = (L + R) // 2
        k = solve(NUMS[mid])
        if k == INF: R = mid
        else:
            ans = min(ans, k)
            L = mid
    print("Case #" + str(case) + ":", ans)