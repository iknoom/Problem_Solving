N,M,K = map(int,input().split())
s = list(map(int,input().split()))
A = [0] * N
for _ in range(K):
	a,b = map(int,input().split())
	A[b-1] = a
	
i = N-1
while s:
	k = s.pop()
	if k == 1: break	
	if k in A:
		while k != A[i]: i -= 1
	else:
		while A[i]: i -= 1
	A[i] = k
	i -= 1

s.reverse()
i = 0
while s:
	k = s.pop()	
	if k in A:
		while k != A[i]:
			if A[i] == 0: A[i] = -1
			i += 1
	else:
		while A[i]: i += 1
	A[i] = k
	i += 1

if 1 in A:
	print(A.index(1) + 1)
else:
	print(A.index(0) + 1)
