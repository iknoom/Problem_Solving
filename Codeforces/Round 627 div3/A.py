import sys
input = sys.stdin.readline

q = int(input())

for _ in range(q):
    N = int(input())
    A = list(map(int, input().split()))
    X = min(A)
    ans = True
    for i in range(N):
        A[i] -= X
        if A[i] & 1:
            ans = False
    if ans:
        print("YES")
    else:
        print("NO")