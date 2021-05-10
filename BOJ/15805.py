N = int(input())
A = list(map(int, input().split()))

p = [-1] * (max(A) + 1)
for i in range(N - 1):
    # i <-> i + 1
    if p[A[i + 1]] < 0: # 부모 -> 자식
        p[A[i + 1]] = A[i]
p[A[0]] = -1

print(len(p))
print(*p)