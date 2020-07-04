N = int(input())
B = []
for _ in range(N):
	s,e,b = map(int,input().split())
	B.append((s,b))
	B.append((e,-b))
ans = 0
cur = 0
for t,b in sorted(B):
	cur += b
	ans = max(ans, cur)
print(ans)
