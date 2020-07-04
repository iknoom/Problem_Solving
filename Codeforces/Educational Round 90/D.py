import sys
input = sys.stdin.readline


T = int(input())

for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    ans = []
    MAX = -1
    for i in range(N):
        for j in range(i + 1, N + 1):
            B = A[:i] + A[i:j][::-1] + A[j:]
            k = 0

            for q in range(N):
                if q % 2 == 0:
                    k += B[q]
            if MAX < k:
                ans = B
                MAX = k
    print(MAX)
    print(ans)
