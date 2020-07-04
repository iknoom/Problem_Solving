N = int(input())
A = []
B = list(map(int, input().split()))
S = 0
for i in range(N):
    A.append(B[i] * (i + 1) - S)
    S += A[-1]
print(*A)