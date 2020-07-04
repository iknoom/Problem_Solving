N,M=map(int,input().split())
p=[1]*N
f=[]
for _ in range(M):
	x,y=map(int,input().split())
	f+=[(x-1,y-1),(y-1,x-1)]
for x,y in sorted(f):
	if p[x]==p[y]:p[y]+=(x<y);p[x]+=(x>y)
print(''.join(map(str,p)))
