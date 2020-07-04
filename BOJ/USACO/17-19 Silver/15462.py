N = int(input())
vst = [-1] * N
E = list(map(int,input().split()))
ans = 0

for i in range(N):
	if vst[i] < 0:
		u = i
		s = [u]
		vst[u] = i
		while True:
			u = E[u] - 1
			if vst[u] == i:
				ans += 1
				while s[-1] != u:
					s.pop()
					ans += 1
				break
				
			elif vst[u] >= 0:
				break
				
			else:
				s.append(u)
				vst[u] = i
				
print(ans)
