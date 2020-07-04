dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
hdx = [1, 1, -1, -1, 2, 2, -2, -2]
hdy = [2, -2, 2, -2, 1, -1, 1, -1]

K = int(input())
W, H = map(int,input().split())
B = [list(map(int,input().split())) for _ in range(H)]
vst = [[[0] * W for _ in range(H)] for _ in range(K+1)]

vst[0][0][0] = 1
q = [(0,0,0)]
for x, y, k in q:
	for i in range(4):
		xx, yy = x + dx[i], y + dy[i]
		if 0 <= xx < W and 0 <= yy < H and not vst[k][yy][xx] and not B[yy][xx]:
			vst[k][yy][xx] = vst[k][y][x] + 1
			q.append((xx,yy,k))
	if k < K:
		for i in range(8):
			xx, yy = x + hdx[i], y + hdy[i]
			if 0 <= xx < W and 0 <= yy < H and not vst[k+1][yy][xx] and not B[yy][xx]:
				vst[k+1][yy][xx] = vst[k][y][x] + 1
				q.append((xx,yy,k+1))
ans = 10**9
for i in range(K+1):
	if vst[i][-1][-1]:
		ans = min(ans, vst[i][-1][-1] - 1)

if ans < 10**9:
	print(ans)
else:
	print(-1)
