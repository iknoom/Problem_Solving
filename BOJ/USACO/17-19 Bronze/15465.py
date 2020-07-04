M = [7] * 3
T = {'B' : 0, 'E' : 1, 'M' : 2}
 
def update():
	ret = 0
	for i in range(3):
		if M[i] == max(M):
			ret += (1 << i)
	return ret
	
S = []
t = 7
ans = 0

N = int(input())
for _ in range(N):
	a, b, c = input().split()
	S.append((int(a), b, int(c)))

S.sort()

for i, n, d in S:
	M[T[n[0]]] += d
	new = update()
	if t != new:
		ans += 1
		t = new
		
print(ans)
