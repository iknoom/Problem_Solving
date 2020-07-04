N = int(input())
C = [tuple(map(int,input().split())) for _ in range(N)]
T = [0] * 1001

def fill(l,r,t):
	for i in range(l,r): T[i] += t

ans = 0
	
for a,b in C:
	fill(a,b,1)

for a,b in C:
	fill(a,b,-1)
	ans = max(ans, sum(T[i] > 0 for i in range(1001)))
	fill(a,b,1)
print(ans)
