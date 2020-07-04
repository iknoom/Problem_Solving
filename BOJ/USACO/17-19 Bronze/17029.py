from itertools import combinations as cb
N = int(input())
a = [set(input().split()[2:]) for _ in range(N)]
ans = 0
for x,y in cb(a,2):
	cnt = 0
	for k in x:
		if k in y: cnt += 1
	ans = max(ans, cnt)
print(ans+1)
