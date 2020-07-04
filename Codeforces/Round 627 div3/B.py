import sys

input = sys.stdin.readline

q = int(input())

for _ in range(q):
    N = int(input())
    A = list(map(int, input().split()))
    if N < 3:
        print("NO")
    else:
        ans = False
        for i in range(N - 2):
            x = A[i]
            for j in range(i + 2, N):
                if A[j] == x:
                    ans = True
        if ans:
            print("YES")
        else:
            print("NO")