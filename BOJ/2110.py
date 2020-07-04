import sys
input = sys.stdin.readline

N, C = map(int,input().split())
X = [int(input()) for _ in range(N)]
X.sort()

def check(d):
	cnt = 1
	x1 = X[0]
	for x2 in X[1:]:
		if x2 - x1 >= d:
			cnt += 1
			x1 = x2
	if cnt < C: return False
	else: return True

L = 0
R = 10**9

while L+1 < R:
	mid = (L + R) // 2
	if check(mid):
		L = mid
	else:
		R = mid
	
print(L)
