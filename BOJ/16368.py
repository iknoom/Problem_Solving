from heapq import *

m, n, w, h = map(int,input().split())
W = list(map(int,input().split()))
D = list(map(int,input().split()))
hq = [(0, -W[i], i) for i in range(m)]
heapify(hq)
ans = True
plans = [[] for _ in range(m)]

for i in range(n):
	while D[i]:
		while hq and W[hq[0][2]] < w: heappop(hq)
		if not hq or i < hq[0][0]: ans = False; break
		p, _, q = heappop(hq)
		
		for j in range(w):
			if D[i + j]: D[i + j] -= 1
			else: ans = False
		
		if not ans: break
		
		W[q] -= w
		plans[q].append(i + 1)
		
		heappush(hq, (i + w + h, -W[q], q))
	if not ans: break

for k in W:
	if k: ans = False
		
if ans:
	print(1)
	for plan in plans:
		print(*plan)
else:
	print(-1)
