from collections import Counter
r,c,k=map(int,input().split())
A=[list(map(int,input().split())) for _ in range(3)]
N=M=3
a=t=0
while 1:
	if a>100:print(-1);break
	if r<=N and c<=M and A[r-1][c-1]==k:print(a);break
	if N<M or (t and N==M):N,M,r,c=M,N,c,r;t^=1;A=[*zip(*A)]
	B=[[] for _ in range(N)]
	for i in range(N):
		D = Counter(A[i])
		if 0 in D:D.pop(0)
		for p,q in sorted(zip(D.values(),D.keys())):B[i]+=[q,p]
	M=min(100,max(len(b) for b in B))
	for i in range(N):B[i]=B[i][:M]+[0]*(M-len(B[i]))
	A=B;a+=1
