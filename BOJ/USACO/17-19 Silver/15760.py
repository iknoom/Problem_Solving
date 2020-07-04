N = int(input())
A = [(int(input()), i) for i in range(N)]
A.sort()
print(max(A[i][1] - i for i in range(N)) + 1)