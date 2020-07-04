dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

M, N = map(int,input().split())
B = [list(map(int,input().split())) for _ in range(M)]
S = sum(sum(B[i]) for i in range(M))
h = 0

def bfs():
	global N, M
	vst = [[False] * N for _ in range(M)]
	vst[0][0] = True
	q = [(0,0)]
	ret = 0
	for x, y in q:
		for i in range(4):
			xx, yy = x + dx[i], y + dy[i]
			if 0 <= xx < N and 0 <= yy < M and not vst[yy][xx]:
				vst[yy][xx] = True
				if B[yy][xx] == 1:
					B[yy][xx] = 0
					ret += 1
				else:
					q.append((xx,yy))
	return ret
				
while True:
	h += 1
	chz = bfs()
	if chz == S:
		break
	else:
		S -= chz
		
print(h)
print(S)
