g = [input() for _ in range(3)]
s1 = set()
s2 = set()

def u(t):
	if len(t) == 1: s1.add(tuple(t))
	elif len(t) == 2: s2.add(tuple(sorted(t)))

tmp = set(g[i][i] for i in range(3))
u(tmp)

tmp = set(g[2-i][i] for i in range(3))
u(tmp)

for x in g:
	tmp = set(x)
	u(tmp)

g = [*zip(*g)]

for y in g:
	tmp = set(y)
	u(tmp)

print(len(s1))
print(len(s2))
