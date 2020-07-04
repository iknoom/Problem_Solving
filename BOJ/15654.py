N, M = map(int,input().split())
A = sorted(map(int,input().split()))
vst = [False] * N

def sol(B):
	if len(B) == M:
		print(*B)
		return
	for v in range(N):
		if not vst[v]:
			vst[v] = True
			sol(B + [A[v]])
			vst[v] = False

sol([])
