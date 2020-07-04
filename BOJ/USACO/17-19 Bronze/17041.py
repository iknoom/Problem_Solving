N = int(input())
S = list(input().split() for _ in range(N))
s, e = 0, N-1
while S[s][0] != "none": s += 1
while S[e][0] != "none": e -= 1

a,b = 0, 1e9
for i in range(e,-1,-1):
	t,x,y = S[i]
	x,y = int(x),int(y)
	if t == "none":
		a = max(a, x); b = min(b, y)
	elif t == "off":
		a += x; b += y
	elif t == "on":
		a -= y; b -= x
	a = max(a,0)
print(a,b)

a,b = 0, 1e9
for i in range(s,N):
	t,x,y = S[i]
	x,y = int(x),int(y)
	if t == "none":
		a = max(a, x); b = min(b, y)
	elif t == "on":
		a += x; b += y
	elif t == "off":
		a -= y; b -= x
	a = max(a,0)
print(a,b)
