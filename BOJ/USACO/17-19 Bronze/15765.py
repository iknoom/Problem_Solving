N, X, Y = input().split()
N = int(N)
parent = {}

for _ in range(N):
	P, C = input().split()
	parent[C] = P
	
X_parent = {}
cnt = 0
p = X
while p in parent:
	cnt += 1
	p = parent[p]
	X_parent[p] = cnt

relation = ""

p = Y
cnt = 0
while True:
	if p in X_parent:
		t = X_parent[p]
		
		if cnt == 0:
			if t > 2: relation += "great-" * (t-2)
			if t > 1: relation += "grand-"
			relation += "mother"		
		elif cnt == 1:
			if t == 1: relation = "SIBLINGS"
			if t > 2: relation += "great-" * (t-2)
			if t > 1: relation += "aunt"		
		else:
			relation = "COUSINS"			
		break
	
	if p not in parent:
		break
	
	p = parent[p]
	cnt += 1

if not relation:
	relation = "NOT RELATED"
	
if relation in ["SIBLINGS", "COUSINS", "NOT RELATED"]:
	print(relation)
else:
	print(Y, "is the", relation, "of", X)
