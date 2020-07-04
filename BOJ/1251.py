A = input()
N = len(A)
ans = []
for i in range(1, N - 1):
    for j in range(i + 1, N):
        ans.append(A[:i][::-1] + A[i:j][::-1] + A[j:][::-1])
print(sorted(ans)[0])