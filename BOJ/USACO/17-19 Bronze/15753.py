n = int(input())
A = list(map(int,input().split()))
ans = 0
for i in range(n):
	if A[i] > 0:
		for j in range(A[i]):
			if A[i - j - 1] < 0:
				A[i - j - 1] = A[i] - j - 1
			elif A[i - j - 1] != A[i] - j - 1:
				ans = -1

if A[0] > 0: ans = -1
A[0] = 0

if ans < 0:
	print(ans)
else:
	a = sum(k == -1 for k in A)
	b = sum(k == 0 for k in A)
	print(b, a+b)
