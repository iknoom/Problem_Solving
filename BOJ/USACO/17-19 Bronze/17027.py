N = int(input())
querys = [tuple(map(int,input().split())) for _ in range(N)]
ans = 0

for s in [2,4,8]:
	cnt = 0
	for query in querys:
		a,b,g = query
		if s & (1 << a): s = (1 << b)
		elif s & (1 << b): s = (1 << a)
		if s & (1 << g): cnt += 1
	ans = max(ans, cnt)
print(ans)
