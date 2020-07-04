N,M=map(int,input().split())
P=[set(map(int,input().split()[1:])) for _ in range(M+1)]
q=list(P[0])
V=[0]*(M+1)
for u in q:
    for i in range(1,M+1):
        if not V[i] and u in P[i]:V[i]=1;q+=list(P[i]-{u})
print(M-sum(V))