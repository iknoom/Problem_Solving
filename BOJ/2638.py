dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

M, N = map(int,input().split())
B = [list(map(int,input().split())) for _ in range(M)]
S = sum(sum(B[i]) for i in range(M))
h = 0

def bfs():
	global N, M, S
	vst = [[0] * N for _ in range(M)]
	vst[0][0] = 1
	q = [(0,0)]
	stack = []
	for x, y in q:
		for i in range(4):
			xx, yy = x + dx[i], y + dy[i]
			if 0 <= xx < N and 0 <= yy < M:
				if B[yy][xx] == 1:
					vst[yy][xx] += 1
					if vst[yy][xx] == 2:
						stack.append((xx,yy))
				elif not vst[yy][xx]:
					vst[yy][xx] = 1
					q.append((xx,yy))
	ret = len(stack)
	for x, y in stack: B[y][x] = 0
	return ret
		
while S:
	h += 1
	S -= bfs()

print(h)
