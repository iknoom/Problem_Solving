N = int(input())
A = sorted(map(int, input().split()))
if A[0] == 1:
    if N > 1 and A[1] == 1:
        print(0)
    else:
        print(1)
else:
    ans = 0
    MAX = 10 ** 6 + 3
    C = [False] * MAX
    for i in range(N):
        if not C[A[i]]:
            if i != N - 1 and A[i] != A[i + 1]:
                ans += 1
            elif i == N - 1:
                ans += 1
            cur = 1
            while cur * A[i] <= MAX:
                C[cur * A[i]] = True
                cur += 1
    print(ans)