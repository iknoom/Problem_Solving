from collections import Counter
N, M = map(int,input().split())
C = Counter(input() for _ in range(N))
K = int(input())
ans = 0
for k in C:
	t = sum(k[i] == '0' for i in range(M))
	if t > K or (K - t) & 1:
		continue	
	ans = max(ans, C[k])
print(ans)
