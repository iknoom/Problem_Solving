N = int(input())
A = list(map(int,input().split()))
A.sort()
S = 0
for k in A:
	if k <= S + 1: S += k
	else: break
print(S + 1)
