N = int(input())
T = [0] * N
for i, j in enumerate(map(int, input().split())):
    T[j - 1] = i
IDs = list(map(int,input().split()))
for _ in range(3):
    tmp = [0] * N
    for i in range(N):
        tmp[T[i]] = IDs[i]
    IDs = tmp
print(*IDs, sep='\n')