N = int(input())
A = list(map(int,input().split()))
c = 1
for i in range(N-1):
	if A[-i-1] > A[-i-2]: c += 1
	else: break
print(N - c)
